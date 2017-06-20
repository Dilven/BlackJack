#include "stdafx.h"
#include "Card.h"
#include <string>

using namespace std;

int Card::getValue()
{
	return value;
}
string Card:: getName()
{
	return name;
}
string Card:: getColor()
{
	return color;
}
ostream& operator<<(ostream& strumien, Card c)
{
	strumien << c.getName() << " " << c.getColor();
	return strumien;
}
Card::Card(int v, string n, string c) :value(v), name(n), color(c) 
{
}


Card::~Card()
{
}

