#ifndef LOCATION_H
#define LOCATION_H
#include "Item.h"
#include <iostream>
#include <fstream>
using namespace std;

class Location{
	private:
		string name;
        string description;
        bool isUnlocked;
        string key;
        Location* next;
        Location* previous;
		Item* items;

	public:
		//Default constructor
		Location(){
			items = nullptr;
			next = nullptr;
			previous = nullptr;
		}


		//Destructor
		~Location(){
			while (items != nullptr) {
		        Item* temp = items;
		        items = items->getNextItem();
		        delete temp;
			}
		}

		//Setter
		void setName(string n){
			name=n;
		}

		void setDes(const string d){
			description = d;
		}

		void setCon(const bool unlock){
			isUnlocked = unlock;
		}

		void setNextLocation(Location *location) {
        	next = location;
         	location->previous = this;
      	}

      	void setPreviousLocation(Location* location) {
       		previous = location;
        	location->next = this;
        }


		//Getter
		string getname() const {
			return name;
		}

		string getdescription() const {
			return description;
		}

		bool condition() const {
			return isUnlocked;
		}

		Location* getNextLocation() {
       		return next;
     	}

     	Location* getPreviousLocation() {
      		return previous;
     	}

    	string keyItem() const {
    		return key;
		}


		////Operation to item list
		
		void appendItem(const string& name, const string& description, int score, bool keyItem) {
		    Item* itemPtr = items;

		    if (itemPtr == nullptr) {
		        items = new Item(name, description, score, keyItem);
		    } else {
		        while (itemPtr->getNextItem() != nullptr) {
		            itemPtr = itemPtr->getNextItem();
		        }
		        itemPtr->setNextItem(new Item(name, description, score, keyItem));
		    }
			
			if(keyItem == true){
				key = name;
			}

		}
		
		//Get the first item saved in location
		Item* getFirstItem() const {
		    return items;
		}

		void displayItem(){
			Item* itemPtr = nullptr;
			itemPtr = items;

			while(itemPtr!= nullptr){
				cout<< "Item Left: " << itemPtr->getItemName() << ", " << itemPtr->getItemDescription()
					<<  ", " << itemPtr->getScore() << ", " << itemPtr->isKeyItem() << endl;

				itemPtr=itemPtr->getNextItem();
			}
		}
		
		Item* searchItem(const string& itemName) {
		    Item* itemPtr = items;

		    while (itemPtr != nullptr) {
				if (itemPtr->getItemName() == itemName) {

			    	//Create a new instance (deep copy)
					Item* copy = new Item;
			        copy->setName(itemPtr->getItemName());
			       	copy->setDes(itemPtr->getItemDescription());
			       	copy->setkey(itemPtr->isKeyItem());
			       	copy->setScore(itemPtr->getScore());
			       	copy->setNextItem(nullptr);

			        return copy;
			    }
			    itemPtr = itemPtr->getNextItem();
			}
			
			//If there is no such item in room
		    return nullptr;
		}

		void removeItem(string name) {
		    Item* itemPtr = items;
		    Item* prevPtr = nullptr;

		    if(!items)
		    	return;

		    if(items->getItemName() == name){

		    	itemPtr = items->getNextItem();
		    	items= itemPtr;

		    	return;

			}else{
				itemPtr = items;

				while(itemPtr != nullptr && itemPtr->getItemName() != name){
					prevPtr = itemPtr;
					itemPtr = itemPtr->getNextItem();
				}
			}

			if(itemPtr){
				prevPtr->setNextItem(itemPtr->getNextItem());
			}
		}

		// Save item list to file
		void saveItemFile (ofstream& file){
			file << "Key Item: " << key << endl;
			cout << "Key";
				  
			if (items == nullptr){ // If no item left in location
				return;

			}else{
				Item *current = items;

		        while (current != nullptr) {
		            file << "Item Left: "<< current->getItemName() << ", " << current->getScore()
		            	 << ", " << current->isKeyItem() << ", " << current->getItemDescription() << endl;

		            current = current->getNextItem();
		        }
		        return;
			}
		}
		
		void setKeyItem(string name){
			key = name;
		}

};
#endif
