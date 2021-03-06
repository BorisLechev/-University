#include "stdafx.h"
#include <iostream>

using namespace std;

void Push(double number);
int Pop(int &n);
void PrintMaxNumberFromTheDeck(int maxNumber);

struct Element
{
	int key;       //стойността на елемента
	Element *next;  //посочва следващия елемент
}*first = NULL, *last = NULL, *p;  //first сочи към първия елемент, а last сочи към последния

void main()
{
	double number;
	int maxNumber = 0;

	cout << "Enter only integer numbers, please. The program will return the biggest one." << endl;
	cout << "Enter oh to exit." << endl << endl;

	do
	{
		cout << "Enter an integer number: ";
		cin >> number;

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

	PrintMaxNumberFromTheDeck(maxNumber);
}

void Push(double number)  //добавяне на елемент със стойност number
{
	p = last;  //p присвоява стойността на последния елемент
	last = new Element; //създаване на нов елемент сочен от last
	last->key = number; //установяване на number за стойност на последния елемент
	last->next = NULL; //следващия елемент last e NULL

	if (p != NULL) //ако няма 
	{
		p->next = last;
	}

	if (first == 0)
	{
		first = last;
	}
}

int Pop(double &number) //извличане на елемент
{
	if (first)  //проверка за наличие на първи елемент
	{
		p = first; //р посочва първия елемент
		number = first->key; //number присвоява стойността на първия елемент
		first = first->next; //first посочва стойността на следващия елемент

		if (first == NULL) //Ако first e NULL изтриваме
		{
			last = first;
		}

		delete p;
		return 1;
	}

	else
	{
		return 0;
	}
}

void PrintMaxNumberFromTheDeck(int maxNumber)  //Принтиране на най - голямото число в дека
{
	maxNumber = first->key;
	p = first;

	while (p->next != 0)
	{
		p = p->next;

		if (maxNumber < p->key)
		{
			maxNumber = p->key;
		}
	}

	cout << endl << "Max number = " << maxNumber << endl;
}
