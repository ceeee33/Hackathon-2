#ifndef GAME_H
#define GAME_H
#include "Location.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class Game{
	private:
		Location* locList;
		Player* player;

	public:
		Game();
		~Game();
		void createGame();
		void start(const string& name);
		void examine();
		void collectItem(const string&);
		void saveProgress();
		void loadProgress(const string&);
		void moveNextLoc();
		void movePrevLoc();
		bool unlockNextRoom(string&);
		bool quit();
		Location* getLocHead();
		void appendLoc(Location*);
		Location* findLocByName(const string&);
		void inventory();
		void playerWin();
		bool checkKeyItem(string&, string&);
		void displaySymbol(const string);
};

Game::Game(){
	locList=nullptr;
	player=nullptr;
}

Game::~Game(){
	while (locList != nullptr) {
	    Location* temp = locList;
	    locList = locList->getNextLocation();
	    delete temp;
	}

	delete player;
}

void Game::createGame(){
	ifstream file("gamelocation.txt");
	if(!file){
		cout<<"Fail to open game location file. "<<endl << endl;
		return;
	}

	string line;
	Location* locPtr = nullptr;
	locPtr = new Location;

	while(getline(file, line)){

		if(line.empty()){
			//Define a new dynamic array
			locPtr = new Location;

			//Skip empty line
			continue;
		}

		if(line.find("Location: ") != string::npos){

			string name, des;

			int colonPos, commaPos;

			colonPos = line.find(":");
			commaPos = line.find(",");

			name = line.substr(colonPos+2, commaPos-colonPos-2);
			des = line.substr(commaPos+2);

			//Set name and description
			locPtr->setName(name);
			locPtr->setDes(des);
			locPtr->setCon(false);

			//Add location to linked list
			appendLoc(locPtr);

			continue;

		} else if(line.find("Item: ") != string::npos){

            if (locPtr == nullptr) {
                cout << "Error: No location defined for item." << endl << endl;
                continue;
            }

			string itemName, itemDes;
			int point, colonPos, comma1Pos, comma2Pos;
			bool keyItem;

			//Find position of ":" and first two consecutive ","
			colonPos = line.find(":");
			comma1Pos = line.find(",");
			comma2Pos = line.find(",", comma1Pos+1);

			//Extract value for each variable
			itemName = line.substr(colonPos+2, comma1Pos-colonPos-2);
			point = stoi(line.substr(comma1Pos+2, comma2Pos-comma1Pos-2));
			keyItem = stoi(line.substr(comma2Pos+2, 1));
			itemDes = line.substr(comma2Pos+4);

			locPtr->appendItem(itemName, itemDes, point, keyItem);

			continue;
		}

	}
	//Close the gamelocation.txt file
	file.close();
}

void Game::start(const string& name){
	//Set up the game
	createGame();
	
	cout << endl << "In a dreary city, a struggling protagonist becomes entangled in a monotonous existence. Yearning for a change, they stumble upon a mysterious opportunity promising wealth and transformation. Driven by desperation and curiosity, they take the leap, unknowingly entering a treacherous game that tests their mettle. As the doors open to an enigmatic world, they confront danger, secrets, and the price of freedom. Will they conquer the challenges?" << endl << endl;
	
	//Set the player's name
	player = new Player;
	player->setName(name);
	
	//Get the first location pointer
	Location* curLoc = locList;
	
	//Set the current location of player
	player->setCurrentLocation(curLoc->getname());
	
	cout << "Hi, " << name << "!" << endl << endl;
	cout << "Welcome to Realm of Enigmas" << endl << endl;
	cout << "Current Location: " << player->getCurrentLocation() << endl;
	cout << endl;
	cout << curLoc->getdescription() << endl << endl;
	displaySymbol(player->getCurrentLocation());
}

//Use when setting up the game
void Game::appendLoc(Location* loc){
	if(locList == nullptr){
		locList = loc;

	}else{
		Location* locPtr = locList;

		while(locPtr->getNextLocation() != nullptr){
			locPtr = locPtr -> getNextLocation();      
		}
		locPtr->setNextLocation(loc);
		loc->setPreviousLocation(locPtr);
	}

}

//Use the location name to get the pointer of that location
Location* Game::findLocByName(const string& locName){
	if (locList == nullptr) {
		cout << "Location haven't set'." << endl << endl;
		return nullptr;

	} else {
		Location* locPtr = locList;

		while (locPtr != nullptr && locPtr->getname()!=locName) {
			locPtr = locPtr->getNextLocation();
		}

		if(locPtr){
			return locPtr;
		}else{
			cout << " Can't find your location." << endl << endl;
			return nullptr;
		}
	}
}

//Show the name and description of current location
void Game::examine(){
	Location* curLoc = findLocByName(player->getCurrentLocation());
	cout << "Current location: "<< curLoc->getname() << endl;
	cout << curLoc->getdescription() << endl;
	displaySymbol(player->getCurrentLocation());
	return;
}

//Collect item based on name of item
void Game::collectItem(const string& itemName){
	//Get the pointer of current location
	Location* curLoc = findLocByName(player->getCurrentLocation());

	//To check there is item to collect in this location
    if (curLoc->getFirstItem() != nullptr) {
    	
    	//If player does not have this item and current location have this item to collect
        if ( (!player->hasItem(curLoc->searchItem(itemName))) && (curLoc->searchItem(itemName)) ){
        	
			//Add the item to inventory
            player->addInventory(curLoc->searchItem(itemName));
            
            //Remove the item from current location
            curLoc->removeItem(itemName);

			//Display the current score of player
            cout << "Your current score: " << player->getScore() << endl << endl;

		} else { //There is no such thing in this location
        	cout << "Invalid item to collect. " << endl << endl;
        }

    } else { 
           cout << "There is nothing to collect in this location" << endl << endl;
    }

    return;
}

void Game::saveProgress(){
	//Set the name of file based on username
	string fileName = player->getName() + "_progress.txt";
	
	//Create the file and open it
	ofstream progressFile(fileName);
	cout << "File created!" << endl;
	
	if (!progressFile){
		cout << "Fail to open file for saving progress. "<<endl;
		return;

	}else{
		cout << "Saving your progress..." << endl << endl;
		
		//Save condition of player
		progressFile << "Player Name: " <<player->getName() <<endl;
		progressFile << "Score: " <<player->getScore() <<endl;

		//Save inventory list of player
		player->saveInvFile (progressFile);

		// Save the player's current location
    	progressFile << "Current Location: " << player->getCurrentLocation() << endl;

		//Save condition for each location
		while(locList != nullptr){

			progressFile << "Location: " << locList->getname() << endl;
			progressFile << "Description: " << locList->getdescription() << endl;
			progressFile << "Condition: " << locList->condition() << endl;

			//Save the item left in each location
			locList->saveItemFile (progressFile);
			
//			progressFile << endl;
			
			locList = locList->getNextLocation();
		}

		//If all thing save sucessfully
		cout << "Game progress save successfully. "<< endl << endl;
	}
	
	progressFile.close();
	cout << "Closing the file..." << endl << endl;;
}

void Game::loadProgress(const string& name){
	string fileName = name + "_progress.txt";

	ifstream loadProFile(fileName);

	cout << "Start loading progress..." << endl;

	if(!loadProFile){
		cout << "Fail to open file for loading progress. " << endl;
		return;

	}else{
		cout << "I found your file! " << endl << endl;

		string line;
		string playerName;
		int playerScore = 0;
		string invItemName;
		Location* location = nullptr;

		while(getline(loadProFile, line)){
			if(line.find("Player Name: ") != string::npos){
				player = new Player;
				playerName = line.substr(line.find(": ")+2);
				player->setName(playerName); 

				continue;

			}else if(line.find("Score: ") != string::npos){
                playerScore = stoi(line.substr(line.find(": ") + 2));
				player->setScore(playerScore);

				continue;

			}else if(line.find("Item Collected: ") != string::npos){

				string itemName, itemDes;
				int point, colonPos, comma1Pos, comma2Pos;
				bool keyItem;

				//Find position of ":" and first two consecutive ","
				colonPos = line.find(":");
				comma1Pos = line.find(",");
				comma2Pos = line.find(",", comma1Pos+1);

				//Extract value for each variable				
				itemName = line.substr(colonPos+2, comma1Pos-colonPos-2);
				point = stoi(line.substr(comma1Pos+2, comma2Pos-comma1Pos-2));
				keyItem = stoi(line.substr(comma2Pos+2, 1));
				itemDes = line.substr(comma2Pos+4);

				player->setInvList(itemName, itemDes, point, keyItem);

				continue;

            }else if(line.find("Current Location: ") != string::npos){
            	string playerCurLoc = line.substr(line.find(": ") + 2);
            	player->setCurrentLocation(playerCurLoc);

            	continue;

			}else if(line.find("Location: ") != string::npos){ 
			
				// Save detail for each location
				string locName = line.substr(line.find(": ") + 2);
				string locDes, conStr;
				bool locCon;

				// Read description and condition for the location
				getline(loadProFile, locDes);
				locDes = locDes.substr(locDes.find(": ")+2);
				getline(loadProFile, conStr);
				locCon = stoi(conStr.substr(conStr.find(": ")+2));
				
				// Define a dynamic pointer for location class
				location = new Location;
				
				// Set detail 
				location->setName(locName);
				location->setDes(locDes);
				location->setCon(locCon);
				
				// Add to locList
				appendLoc(location);

				continue;
				
			}else if(line.find("Item Left: ") != string::npos){
				
				// Read items left in location

				string itemName, itemDes;
				int point, colonPos, comma1Pos, comma2Pos;
				bool keyItem;

				//Find position of ":" and first two consecutive ","
				colonPos = line.find(":");
				comma1Pos = line.find(",");
				comma2Pos = line.find(",", comma1Pos+1);
						
				itemName = line.substr(colonPos+2, comma1Pos-colonPos-2);
				point = stoi(line.substr(comma1Pos+2, comma2Pos-comma1Pos-2));
				keyItem = stoi(line.substr(comma2Pos+2, 1));
				itemDes = line.substr(comma2Pos+4);

				location->appendItem(itemName, itemDes, point, keyItem);

				continue;

			}else if(line.find("Key Item: ") != string::npos){ 

				location->setKeyItem(line.substr(line.find(": ")+2));
				continue;
			}else{ //If is a empty line
				delete location;
				location = nullptr;
				
				continue;
			}

		}

		cout<<"Game progress loaded sucessfully. " << endl;
		loadProFile.close();
		
		cout << "Hi, " << name << "!" << endl << endl;
		cout << "Welcome to Realm of Enigmas" << endl << endl;
	}
}


bool Game::unlockNextRoom(string& key){

	Location* curLoc = findLocByName(player->getCurrentLocation());
	string realKey = curLoc->keyItem();

	if(! (player->checkItem(key))){
		cout << "You do not have this item in your inventory list." << endl << endl;
		
		return 0;
	}

	// If it is not the last location
	if(curLoc->getNextLocation() != nullptr){

		// If next room is unlocked
		if (curLoc->getNextLocation()->condition()){
			cout << "The next location is unlocked previously. " <<endl;
			return 0;

		}else{ // If next room is not unlocked.

			if (checkKeyItem(key, realKey)){ //If the key is correct key
				curLoc->getNextLocation()->setCon(1);
				moveNextLoc();
			}

			return 0;
		}

	}else { //If it is the last room
		if (checkKeyItem(key, realKey)){ // If is correct key
			//Tell player they win the game
			playerWin();
			return 1;
		}else{
			return 0;
		}
	}
}

bool Game::checkKeyItem(string& key, string& realKey){
	if (key == realKey){
		cout << "Unlock successfully! " << endl << endl;
		return 1;

	}else{
		cout << "Wrong key item. Next location failed to unlock. " << endl << endl;
		return 0;
	}
}

void Game::moveNextLoc(){
	Location* curLoc = findLocByName(player->getCurrentLocation());

	if(curLoc->getNextLocation() == nullptr){ //Check if player is at last room
		cout << "This is the last location." << endl;
		return;

	}else{
		if (curLoc->getNextLocation()->condition()){
			curLoc = curLoc->getNextLocation();
			player->setCurrentLocation(curLoc->getname()) ;

			cout << "You have move to next room! " << endl << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout << "Current Location: " << player->getCurrentLocation() << endl << endl;
			cout << curLoc->getdescription() << endl << endl;
			displaySymbol(player->getCurrentLocation());

		}else{
			cout << "The next room is locked. You need to unlock it first. "<<endl;
		}
	}
}

void Game::movePrevLoc(){
	Location* curLoc = findLocByName(player->getCurrentLocation());

	//If player is at first room
	if(curLoc->getPreviousLocation() == nullptr){
		cout << "This is the first room. " << endl;

	}else{
		curLoc = curLoc->getPreviousLocation();
		player->setCurrentLocation(curLoc->getname());
		
		cout << "You have move to previous room! " << endl << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout << "Current Location: " << player->getCurrentLocation() << endl << endl;
		cout << curLoc->getdescription() <<endl<< endl;
		displaySymbol(player->getCurrentLocation());
	}
}

bool Game::quit(){ // If return 1, quit the game
	int quit = 0;
	cout << "Do you wish to quit the game? " << endl;
	cout << "1: Yes" << endl;
	cout << "0: No" << endl << endl;
	cout << ">";
	cin >> quit;

	if(quit == 0){
		cout << "Continue the game. " << endl << endl;
		return 0;

	}else{
		saveProgress();
		cout << endl << " Though your journey in the game was cut short, we appreciate your participation and the courage it took to embark on this adventure. Remember, every experience contributes to the tapestry of your life, shaping the person you are becoming. As you move forward, may you find new paths that ignite your curiosity and lead you to extraordinary discoveries." << endl;
		cout << "Thanks for playing the game. See you next time! " << endl;
		return 1;
	}
}

void Game::inventory(){
	player->showInventory();
	return;
}

void Game::playerWin(){
	
	cout << R"( 
   ____   U  ___ u  _   _     ____     ____        _       _____    _   _    _         _       _____             U  ___ u  _   _
U /"___|   \/"_ \/ | \ |"| U /"___|uU |  _"\ u U  /"\  u  |_ " _|U |"|u| |  |"|    U  /"\  u  |_ " _|     ___     \/"_ \/ | \ |"|
\| | u     | | | |<|  \| |>\| |  _ / \| |_) |/  \/ _ \/     | |   \| |\| |U | | u   \/ _ \/     | |      |_"_|    | | | |<|  \| |>
 | |/__.-,_| |_| |U| |\  |u | |_| |   |  _ <    / ___ \    /| |\   | |_| | \| |/__  / ___ \    /| |\      | | .-,_| |_| |U| |\  |u
  \____|\_)-\___/  |_| \_|   \____|   |_| \_\  /_/   \_\  u |_|U  <<\___/   |_____|/_/   \_\  u |_|U    U/| |\u\_)-\___/  |_| \_|
 _// \\      \\    ||   \\,-._)(|_    //   \\_  \\    >>  _// \\_(__) )(    //  \\  \\    >>  _// \\_.-,_|___|_,-.  \\    ||   \\,-.
(__)(__)    (__)   (_")  (_/(__)__)  (__)  (__)(__)  (__)(__) (__)   (__)  (_")("_)(__)  (__)(__) (__)\_)-' '-(_/  (__)   (_")  (_/   )" << endl;
	
	cout << endl;
	cout << "Congratulations, victorious champion! You have overcome all challenges and emerged as the winner of the game. Your determination and skill have led you to claim the ultimate prize. Enjoy the glory of your achievement! Well done!" << endl;
	cout << "Your score: " << player->getScore() << endl << endl;
	cout << "Saving your progress. You can come back next time to collect more items and improve your score!" << endl;
	saveProgress();
	
	cout << endl << "Thanks for playing the game. See you next time! " << endl;
}

void Game::displaySymbol(const string name){
	if (name == "Enchanted Grotto - Unveiling Secrets of the Ancient Cave"){
		cout << R"(    
           ______
        .-"      "-.
       /            \
      |              |
      |,  .-.  .-.  ,|
      | )(__/  \__)( |
      |/     /\     \|
      (_     ^^     _)
       \__|IIIIII|__/
        | \IIIIII/ |
        \          /
         `--------`
     
     )" <<endl;
		
	}else if(name == "Whispering Falls - Enigmatic Secrets of the Shadowed Grove"){
		cout << R"(
		
   ___(                        )
   (                          _)
  (_                       __))
    ((                _____)
      (_________)----'
         _/  /
        /  _/
      _/  /
     / __/
   _/ /
  /__/
 //
/'

)" <<endl;	
		
	}else if(name == "Atlantis Chamber - Lost Civilization Revealed"){
		cout << R"(
		
         .-;':':'-.
        {'.'.'.'.'.}
         )        '`.
        '-. ._ ,_.-='
          `). ( `);(
          ('. .)(,'.)
           ) ( ,').(
          ( .').'(').
          .) (' ).('
           '  ) (  ).
            .'( .)'
              .).'

)"<<endl;
		
	}else if(name == "Eternal Echoes - Gateway to Temporal Enigma"){
		cout << R"(


                 _____
              _.'_____`._
            .'.-'  12 `-.`.
            /,' 11      1 `.\
          // 10      /   2 \\
          ;;         /       ::
          || 9  ----O      3 ||
          ::                 ;;
          \\ 8           4 //
            \`. 7       5 ,'/
            '.`-.__6__.-'.'
              ((-._____.-))
              _))       ((_
            '--'         '--'
                    
)"<<endl;
		
	}
}
#endif
