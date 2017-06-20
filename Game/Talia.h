#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <vector>
#include "Card.h"
#include <ctime>

using namespace std;

class Talia
{


public:
	vector<Card> talia;
	
	void add(Card);// dodawanie karty do talii
	Card popCard(); //wyciaganie karty z talii
	void createFull();
	int ValueTalia();
	Talia();
	~Talia();

	
};


