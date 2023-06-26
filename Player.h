#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"

class Player{
	private:
		string name;
		int score;
		string curLocName;
		Item *inventory;

	public:
		Player(string n){
			name = n;
			score = 0;
			inventory = nullptr;	
		}
		
		
		
		~Player(){
			while (inventory != nullptr) {
	        Item* temp = inventory;
	        inventory = inventory->getNextItem();
	        delete temp;
		}
		}
		
		//setter
		void setCurrentLocation(string loc){
			curLocName = loc;
		}
		
		void setScore(int s){
			score = s;
		}
		
		//getter
		string getName() const{
			return name;
		}
		
		int getScore() const{
			return score;
		}
		
		string getCurrentLocation() const {
        	return curLocName;
    		}

		
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
		
		
		void addInventory(Item *item){
			if(hasItem(item)){
				return;
			}
	
			if(inventory == nullptr){
				inventory = item;
				
			}else{
				Item *current =inventory;
		
				while(current->getNextItem() != nullptr){
					current = current -> getNextItem();      //the 'next' is define in class Item, private: Item *next;
				}
				current->setNextItem(item);
			}
			
		score += item->getScore();
		}

		void showInventory() {
		    if (inventory == nullptr) {
		        cout << "Inventory is empty." << endl;
		    } else {
		        Item *current = inventory;
		        cout << "Inventory: "<<endl;
		        while (current != nullptr) {
		            cout << current->getItemName() << endl;
		            current = current->getNextItem();
		        }
		        cout << endl;
		    }
		}
		
		
		
};

#endif
