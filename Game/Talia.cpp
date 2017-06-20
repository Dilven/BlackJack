#include "stdafx.h"
#include "Talia.h"
#include "Card.h"

void Talia::add(Card c)
{
	talia.push_back(c);
}

Card Talia::popCard()
{
	srand(time(0));
	int index = rand() % talia.size();
	Card tmp = talia[index];
	talia.pop_back();
	return tmp;
}



void Talia::createFull()
{
	string kolory[4] = { "kier","karo","pik","trefl" };
	string figury[13] = { "2","3","4","5","6","7","8","9","10","Walet","Dama","Krol","As" };
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<9; j++) //2-10
		{
			Card tmp(j + 2, figury[j], kolory[i]); //generujemy kartê
			talia.push_back(tmp); //dodajemy do talii
		}
		for (int j = 9; j<12; j++) //walet, dama, krol
		{
			Card tmp(10, figury[j], kolory[i]); //generujemy kartê
			talia.push_back(tmp); //dodajemy do talii
		}
		Card tmp(11, figury[12], kolory[i]); //as
		talia.push_back(tmp); //dodajemy do talii
	}

}

int Talia::ValueTalia()

{
	return talia.size();
}

Talia::Talia()
{
}


Talia::~Talia()
{
}
