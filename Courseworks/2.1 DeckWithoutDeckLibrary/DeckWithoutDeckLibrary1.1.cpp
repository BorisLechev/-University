#include "stdafx.h"
#include <iostream>

using namespace std;

void Push(double number);
int Pop(double &number);
void PrintMaxNumberFromTheDeck(int maxNumber, int counter);

struct Element
{
	int key;       //стойността на елемента
	Element *next;  //посочва следващия елемент
}*first = NULL, *last = NULL, *p;  //first сочи към първия елемент, а last сочи към последния

void main()
{
	double number;
	int maxNumber = 0;
	int counter = 0;

	cout << "Enter only integer numbers, please. The program will return the biggest one." << endl;
	cout << "Enter oh to exit." << endl << endl;

	do
	{
		cout << "Enter an integer number: ";
		cin >> number;
		counter++;

		if (number != round(number))
		{
			cout << number << " It's not an integer number." << endl;
			continue;
		}

		Push(number);

	} while (number != 0);

	if (first == 0)
	{
		return;
	}

	PrintMaxNumberFromTheDeck(maxNumber, counter);
}

void Push(double number)  //добавяне на елемент със стойност number
{
	p = last;  //p присвоява стойността на последния елемент
	last = new Element; //създаване на нов елемент сочен от last
	last->key = number; //установяване на number за стойност на последния въведен елемент отговарящ на усл.
	last->next = NULL; //следващия елемент last e NULL

	if (p != NULL) //ако указателя не е празен
	{
		p->next = last;
	}

	if (first == 0) //ако е празен (само първия елемент)
	{
		first = last;
	}
}


int Pop(double &number) //извличане на елемент
{
	if (first)  //проверка за наличие на първи елемент
	{
		p = first; //р посочва първия елемент
		number = first->key; //number присвоява стойността на първия въведен елемент отговарящ на усл.
		first = first->next; //first посочва стойността на следващия елемент

		if (first == NULL) //Ако няма първи елемент
		{
			last = first; //зануляваме
		}

		delete p; //изтриваме указателя р
		return 1;
	}

	else
	{
		return 0;
	}
}

void PrintMaxNumberFromTheDeck(int maxNumber, int counter)  //Принтиране на най - голямото число в дека
{
	double number;
	bool IsMaxNumber = false;
	maxNumber = first->key;

	for (int i = 0; i < counter; i++)  //цикъл за обхождане на дека
	{
		Pop(number);       //извличане на крайния ляв елемент 

		if (number > maxNumber)             
		{
			maxNumber = number;
			IsMaxNumber = true;
		}

		Push(number); //добавяне на извлечения елемент 
	}

	if (IsMaxNumber)
	{
		Push(IsMaxNumber);
	}

	cout << endl << "Max number = " << maxNumber << endl;
}
