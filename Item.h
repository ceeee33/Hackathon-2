#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

using namespace std;

class Item {
private:
    string name;
    string description;
    int score;
    bool keyItem;
    Item* next;

public:
	//Constructor
    Item(const string& name, const string& description, int score, bool keyItem)
        : name(name), description(description), score(score), keyItem(keyItem), next(nullptr) {}

	Item(){
		name = "";
		description = "";
		score = 0;
		keyItem = 0;
		next = nullptr;
	}

	//Getter
    string getItemName() const {
        return name;
    }

    string getItemDescription() const {
        return description;
    }

    int getScore() const {
        return score;
    }

    bool isKeyItem() const {
        return keyItem;
    }

    Item* getNextItem() const {
        return next;
    }


	//Setter
    void setNextItem(Item* item) {
        next = item;
    }

    void setName(const string& n){
    	name = n;
	}

	void setDes(const string& d){
		description = d;
	}

	void setkey(const bool& keyI){
		keyItem = keyI;
	}

	void setScore(const int& s){
		score = s;
	}

};

#endif
