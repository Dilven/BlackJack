#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class Card
{

private:

	int value;
	string name;
	string color;

public:

	string getColor();
	string getName();
	int getValue();
	Card(int,string, string);
	~Card();
	
	
	void Tasuj();

};

ostream & operator<<(ostream & strumien, Card c);
