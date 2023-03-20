#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Card
{
private:
	int value; 
	int feature;  // from 1 to 4 ( 4-C, 3-R, 2-T, 1-B )

public:
	Card() {
		//srand(time(NULL));
		setValue();
		setFeature();		
	}


	~Card(){
	}


	void display() {
		cout << "value: " << value << endl;
		cout << "Feature: " << feature << endl;
	}

	void setValue() {
		value = rand() % 10 + 1;
	}

	void setFeature() {
		feature = rand() % 4 + 1;
	}

	int getValue() {
		return value;
	}

	int getFeature() {
		return feature;
	}

};

