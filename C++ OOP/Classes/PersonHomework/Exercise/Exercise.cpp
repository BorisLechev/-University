#include "pch.h"
#include "Person1.h"
#include <iostream>

using namespace std;

void main()
{
	std::string Name = "";
	std::string Gender = "";
	long long UniqueCitizenshipNumber = 0;

	cout << "Enter a name: ";
	std::getline(std::cin, Name);

	cout << "Enter gender: ";
	cin >> Gender;

	cout << "Enter the unique citizenship number: ";
	cin >> UniqueCitizenshipNumber;

	Person1 person(Name, Gender, UniqueCitizenshipNumber);

	cout << person.GetName() << endl;
	cout << person.GetGender() << endl;
	cout << person.GetUniqueCitizenshipNumber() << endl;
}