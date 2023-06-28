#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include <fstream>

class Player{
	private:
		string name;
		int score;
		string curLocName;
		Item *inventory;


	public:
		//Constructor
		Player(){
			name = "";
			score = 0;
			curLocName = "";
			inventory = nullptr;
		}

		//Destructor
		~Player(){
			while (inventory != nullptr) {
		        Item* temp = inventory;
		        inventory = inventory->getNextItem();
		        delete temp;
			}
		}

		//Setter
		void setName(string n){
			name = n;
		}

		void setCurrentLocation(string loc){
			curLocName = loc;
		}

		void setScore(int s){
			score = s;
		}

		//Getter
		string getName() const{
			return name;
		}

		int getScore() const{
			return score;
		}

		string getCurrentLocation() const {
        	return curLocName;
    	}
		
		
		////Operation to inventory list
		
		//Check the item is in inventory list or not
		bool hasItem(Item *item){
			Item *current = inventory;
			while (current!=nullptr){
				if(current==item){
					return true;
				}
				current = current->getNextItem();
			}
			return false;
		}

		//Append item to inventory
		void addInventory(Item *item){
			if(hasItem(item)){
				return;
	    	}

			if(inventory == nullptr){
				inventory = item;

			}else{
				Item *current = inventory;

				while(current->getNextItem() != nullptr){
					current = current -> getNextItem();      
				}
				current->setNextItem(item);
			}

			cout << "You have collected the " << item->getItemName() << "." << endl;

	        cout << "Your score has increased by " << item->getScore() << "." << endl;
			score += item->getScore();
		}

		void showInventory() {
		    if (inventory == nullptr) {
		        cout << "Inventory is empty." << endl;
		        return;
		    } else {
		        Item *current = inventory;
		        cout << "Inventory: "<<endl;
		        while (current != nullptr) {
		            cout << current->getItemName() << ": " << current->getItemDescription() << endl;
		            current = current->getNextItem();
		        }
		        cout << endl;
		    }
		}


		//Save inventory to file
		void saveInvFile (ofstream& file){

			if (inventory == nullptr){
				return;

			}else{
				Item *current = inventory;

		        while (current != nullptr) {
		            file << "Item Collected: "<< current->getItemName() << ", " << current->getScore()
					 	 << ", " << current->isKeyItem() << ", " << current->getItemDescription() << endl;

		            current = current->getNextItem();
		        }
			}
		}
		
		//Load inventory from file
		void setInvList(const string& name, const string& description, const int score, const bool keyItem){
			Item* itemPtr = inventory;

		    if (itemPtr == nullptr) {
		        inventory = new Item(name, description, score, keyItem);
		    } else {
		        while (itemPtr->getNextItem() != nullptr) {
		            itemPtr = itemPtr->getNextItem();
		        }
		        itemPtr->setNextItem(new Item(name, description, score, keyItem));
		    }

		}
		
		bool checkItem(string name){
			if(inventory == nullptr){
				return 0;

			} else {
				Item* current = inventory;

				while(current != nullptr){
					if(current->getItemName() == name){
						return 1;
					}
					current = current->getNextItem();
				}
				return 0;
			}
		}

};

#endif
