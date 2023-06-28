#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(){
	Game game;
	string name;

	cout << R"(


¦¦     ¦¦ ¦¦¦¦¦¦¦ ¦¦       ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦    ¦¦¦ ¦¦¦¦¦¦¦     ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦
¦¦     ¦¦ ¦¦      ¦¦      ¦¦      ¦¦    ¦¦ ¦¦¦¦  ¦¦¦¦ ¦¦             ¦¦    ¦¦    ¦¦
¦¦  ¦  ¦¦ ¦¦¦¦¦   ¦¦      ¦¦      ¦¦    ¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦          ¦¦    ¦¦    ¦¦
¦¦ ¦¦¦ ¦¦ ¦¦      ¦¦      ¦¦      ¦¦    ¦¦ ¦¦  ¦¦  ¦¦ ¦¦             ¦¦    ¦¦    ¦¦
 ¦¦¦ ¦¦¦  ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦      ¦¦ ¦¦¦¦¦¦¦        ¦¦     ¦¦¦¦¦¦

	
	¦¦¦¦¦¦  ¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦      ¦¦¦    ¦¦¦      ¦¦¦¦¦¦  ¦¦¦¦¦¦¦
	¦¦   ¦¦ ¦¦      ¦¦   ¦¦ ¦¦      ¦¦¦¦  ¦¦¦¦     ¦¦    ¦¦ ¦¦
	¦¦¦¦¦¦  ¦¦¦¦¦   ¦¦¦¦¦¦¦ ¦¦      ¦¦ ¦¦¦¦ ¦¦     ¦¦    ¦¦ ¦¦¦¦¦
	¦¦   ¦¦ ¦¦      ¦¦   ¦¦ ¦¦      ¦¦  ¦¦  ¦¦     ¦¦    ¦¦ ¦¦
	¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦ ¦¦      ¦¦      ¦¦¦¦¦¦  ¦¦
	
	
	¦¦¦¦¦¦¦ ¦¦¦    ¦¦ ¦¦  ¦¦¦¦¦¦  ¦¦¦    ¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦¦¦
	¦¦      ¦¦¦¦   ¦¦ ¦¦ ¦¦       ¦¦¦¦  ¦¦¦¦ ¦¦   ¦¦ ¦¦
	¦¦¦¦¦   ¦¦ ¦¦  ¦¦ ¦¦ ¦¦   ¦¦¦ ¦¦ ¦¦¦¦ ¦¦ ¦¦¦¦¦¦¦ ¦¦¦¦¦¦¦
	¦¦      ¦¦  ¦¦ ¦¦ ¦¦ ¦¦    ¦¦ ¦¦  ¦¦  ¦¦ ¦¦   ¦¦      ¦¦
	¦¦¦¦¦¦¦ ¦¦   ¦¦¦¦ ¦¦  ¦¦¦¦¦¦  ¦¦      ¦¦ ¦¦   ¦¦ ¦¦¦¦¦¦¦  )" << endl;
	
	int newPlayer;
	
	cout << "Are you a new player? " << endl;
	cout << "1: Yes " << endl;
	cout << "0: No" << endl;
	cout << ">";
	cin >>newPlayer;
	cin.ignore();
	
	while(newPlayer!=1 && newPlayer!=0){
		cout<<"Please enter a valid input."<<endl;
		cin.clear(); //Clear any error flags
		cout<<">";
		cin>>newPlayer;
		cin.ignore();
		
	}
	
	cout << static_cast<bool>(newPlayer)<<endl;
	
	cout << R"(  

.___.  ..___..___.__   .   ,.__..  ..__   .  ..__..  ..___
[__ |\ |  |  [__ [__)   \./ |  ||  |[__)  |\ |[__]|\/|[__
[___| \|  |  [___|  \    |  |__||__||  \  | \||  ||  |[___

               )" << endl;
	cout << ">" ;
	getline(cin, name);
	cout << endl;
	
	string fileName = name+"_progress.txt";
	ifstream file(fileName);
	
	if(file){
		game.loadProgress(name);
		game.examine();
	}else{
		//If is a new player, check the name has been used by other or not
		if(newPlayer){
			while(file){
				cout << "Your name has been used by other. " << endl;
				cout << "Please think a new name." << endl;
				cin >> name;
				string filename = name+"_progress.txt";	
			}	
		cout << endl << "This new can be used!" << endl;
		}
		
		game.start(name);
	}

	bool endGame = 0;
	string item;
	char loc;
	string key;

	do{
		char choice = '8';
		cout << "Which action would you like to perform? " <<endl;
		cout << "1. Examine " << endl;
		cout << "2. Show Inventory" << endl;
		cout << "3. Collect Item" << endl;
		cout << "4. Move" << endl;
		cout << "5. Unlock Next Location" << endl;
		cout << "6. Quit The Game" << endl;
		cout << ">";
		cin >> choice;
		
		switch(choice){
			case '1': game.examine();
					break;
			case '2': game.inventory();
					break;
			case '3': cin.ignore();
					cout << "Which item you like to collect? " <<endl;
					cout << ">";
					getline(cin, item);
					game.collectItem(item);
					break;

			case '4': cout << "You can choose to move to the next room or to the previous room. " <<endl;
					cout << "Which room would you like to move to? " << endl;
					cout << "N: Next Room" << endl;
					cout << "P: Previous Room" << endl;
					cout << "C: Cancel / Current Room" << endl;
					cout << ">";
					cin >> loc;
					if (loc == 'N' || loc == 'n'){
						game.moveNextLoc();

					}else if (loc == 'P' || loc == 'p'){
						game.movePrevLoc();

					}else if (loc == 'C' || loc == 'c'){
						cout << "Remain at Current Location" << endl << endl;
						game.examine();
					}else{
						cout << "Invalid input. Quit this action. " << endl << endl;
					}
					break;
			case '5': cout << "Use what to unlock? " << endl;
					cout << ">";
					cin.ignore();
					getline(cin, key);
					endGame = game.unlockNextRoom(key);
					break;
			case '6': endGame = game.quit();
					break;
			default: cout << "Invalid input. Please enter your choice again. " << endl << endl;
					break;

		}

	}while (endGame == 0);

	cout << R"( 
 _______  ___  ___  _______     ___
|   _  "\|"  \/"  |/"     "|   |"  |
(. |_)  :)\   \  /(: ______)   ||  |
|:     \/  \\  \/  \/    |     |:  |
(|  _  \\  /   /   // ___)_   _|  /
|: |_)  :)/   /   (:      "| / |_/ )
(_______/|___/     \_______)(_____/  

)";

    return 0;

}
