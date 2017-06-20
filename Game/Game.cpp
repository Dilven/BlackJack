// Game.cpp : Defines the entry point for the console application.
//


// int ValueTalia = talia.ValueTalia(); //liczba pozosta³ych kart w tali


#include "stdafx.h"
#include "Card.h"
#include "Talia.h"
#include <vector>
#include <ctime>
#include <string>
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <list>
#include "Game.h"
#include <conio.h>
list <int> lista;
int wybor;

Talia talia, gracz1, gracz2;


void Stand(vector<Card> Karty_Krupiera, vector<Card> Talia, int sum_gracz) // wyswietlanie co ma krupier
{
	cout << "Krupier ma: ";
	cout << Karty_Krupiera[0].getName() << " " << Karty_Krupiera[0].getColor() << " ";//wyswietlenie nazwy,koloru i wartosci na ekrnaie
	cout << Karty_Krupiera[1].getName() << " " << Karty_Krupiera[1].getColor() << " ";

	bool wynik = false;
	int Sum = 0;
	int j = 2; // dzieki tej zmiennej wyrzucam nazwe i kolor ostatniej karty

	while (wynik == false); // petla do momentu roztrzygniecia
	{
		
		for (int i = 0; i < Karty_Krupiera.size();i++)
		{
			Sum = Sum + Karty_Krupiera[i].getValue();
		}
		cout << "suma to " << Sum << endl;
		if ((Sum < sum_gracz)&& (Sum<20)) // dobieranie karty dla krupiera
		{
			j++;
			gracz1.add(talia.popCard());// pobranie karty z tali dla gracza nr 2
			Card dobrana(gracz1.popCard());
			Karty_Krupiera.push_back(dobrana);
			cout << Karty_Krupiera[j].getName() << " " << Karty_Krupiera[j].getColor() << " ";

		}
		
		else if ((Sum > sum_gracz)&& (Sum < 22))
		{
			cout << "Przegrales !1212!!";
			while (getchar() != '\n')
			wynik = true;

		}
		else if ((Sum == 21) && (sum_gracz == 21))
		{

			cout << "JEST REMIS :) ";
			while (getchar() != '\n')
			wynik = true;

		}
		else
		{

			cout << "Wygrales !!!";
			while (getchar() != '\n')
			wynik = true;
			
		}
		
	
	
} 

}


void exit()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Koniec programu!";
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

int Sum(vector <Card> Karty_Gracza)
{
	
	int Sum = 0;
	for (int i = 0; i < Karty_Gracza.size();i++)
	{
		Sum = Sum + Karty_Gracza[i].getValue();
	}

	return Sum;
}



void wyswietl()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Witamy w BlackJacku" << endl;
	cout << "---------------------------" << endl;
	cout << "Krupier tasuje karty";

	Sleep(2000);
	cout << ".";
	Sleep(2000);
	cout << ".";
	Sleep(2000);
	cout << "."<<endl;
	Sleep(2000);
	cout << "Okej gotowe! Rozdajemy karty.";
	Sleep(2000);
	
	system("CLS");

	
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //wylaczenie zielonego koloru

}

vector<Card> dobierz(vector<Card> Karty_Gracza , vector<Card> Talia)
{
	
	system("CLS");
	gracz2.add(talia.popCard());// pobranie karty z tali dla gracza nr 2
	Card dobrana(gracz2.popCard());
	Karty_Gracza.push_back(dobrana);
	
	cout << " DOSTALES: " << Karty_Gracza[2].getName() << " " << Karty_Gracza[2].getColor() << " || " << endl;


	/*cout << "Krupier ma: " << n1 << " " << c1;//wyswietlenie nazwy,koloru i wartosci na ekrnaie
	cout << " || ???" << endl << endl << endl;

	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//wy³aczenie koloru	
	cout << " TWOJE KARTY: " << Karty_Gracza[0].getName() << " " << Karty_Gracza[0].getColor() << " || ";
	cout << Karty_Gracza[1].getName() << " " << Karty_Gracza[1].getColor() <<" || "<< Karty_Gracza[2].getName() << " " << Karty_Gracza[2].getColor()<<  endl << endl << endl;
	*/
	return Karty_Gracza;
}




//------------------------

using namespace std; 

int main()
{
	int p;
	srand(time(NULL)); //

	cout << "Witamy w BlackJacku !" << endl;
	cout << "Chcesz zagrac?" << endl<<endl;
	cout << "---------------------------" << endl;
	cout << "1. Tak chce zagrac" << endl;
	cout << "2. Odchodze" << endl;
	cout << "---------------------------" << endl;
	cout << "Wybor: ";
	cin >> p;


	switch (p)
	{
	case 1:  cout << "Lets start" << endl;; break;
	case 2:  exit();  break;

	default:
		cout << "POMYLKA!";
		Sleep(2000);
		break;

		return 0;
	}

	talia.createFull();

	//DWIE KARTY KRUPIERA
	gracz1.add(talia.popCard());// pobranie karty z tali dla gracza nr 1
	Card one(gracz1.popCard()); //przypisanie pobranej karty do obiektu "one"
	gracz1.add(talia.popCard());  //ponowne pobranie karty z tali dla gracza nr 1
	Card sec(gracz1.popCard());	  //pprzypisanie pobranej karty do obiektu "sec" -dla krupiera
	




	//-----------------------------------------------------------------------------------------
	wyswietl();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//wy³aczenie koloru																											  



	//GRACZ 

	gracz2.add(talia.popCard());// pobranie karty z tali dla gracza nr 2
	Card Player_one(gracz2.popCard());
	gracz2.add(talia.popCard()); //ponowne pobranie karty z tali dla gracza nr 2
	Card Player_sec(gracz2.popCard());
	
	

	vector<Card> Karty_Gracza;
	vector<Card> Karty_Krupiera;
	Karty_Krupiera.push_back(one);
	Karty_Krupiera.push_back(sec);

	Karty_Gracza.push_back(Player_one); //dodanie do vektora obecnych kart
	Karty_Gracza.push_back(Player_sec);

	bool koniec = false;
	
	bool koniec_gry=false;


	while(koniec_gry==false)
	{
		Sum(Karty_Gracza);

		int Value_Player;
		Value_Player = Sum(Karty_Gracza);
		if(koniec == false)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //wlaczenie koloru
			cout << "Krupier ma: " << one.getName() << " " << one.getColor();//wyswietlenie nazwy,koloru i wartosci na ekrnaie
			cout << " || ???" << endl << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	//wy³aczenie kolor
		}
		
		
		

		
		cout << endl << endl << " TWOJE KARTY!!!!!: ";
			for (int j = 0; j < Karty_Gracza.size();j++)
			{
				cout << Karty_Gracza[j].getName() << " " << Karty_Gracza[j].getColor() << " || ";//wyswietlenie nazwy,koloru i wartosci na ekrnaie
			}

		
		
		 
		if (Value_Player < 21)
		{
			cout <<endl<< " Mozliwosci wyboru:" << endl;
			cout << "---------------------------" << endl;
			cout << "1.  Dobieram" << endl;
			cout << "2.  Stoje    (priorytet 2)" << endl;
			cout << "3.  exit" << endl;
			cout << "---------------------------" << endl;
			cout << "Wybor: ";
			cin >> wybor;




			switch (wybor)
			{
			case 1:   
				Karty_Gracza=dobierz(Karty_Gracza, talia.talia); break;
			case 2: 

					koniec = true;
					Stand(Karty_Krupiera,talia.talia, Value_Player);
			
				
				break;
			case 3:  exit();       break;


			default:
				cout << "POMYLKA!";
				Sleep(2000);
				break;
			}
		}

		else if(Value_Player == 21)
		{

		
			koniec = true;
			cout << "Trafiles oczko! Sprawdzmy co ma krupier";
			Sleep(3000);
			system("CLS");
			Stand(Karty_Krupiera, talia.talia, Value_Player);
			
		}
		else
		{

			koniec_gry = true;
			cout <<endl<< "Przegrales. Przekroczyles 21 " << endl;
		}
		
	}

		






	Sleep(5000); //po zakonczeniu gry czeka 5sec
	



}
