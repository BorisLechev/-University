#include "pch.h"
#include "Computer.h"
#include "Laptop.h"
#include <iostream>

using namespace std;

void main()
{
	float speed = 0;
	int ram = 0;
	int hdd = 0;
	int batteryTime = 0;
	float weight = 0;

	cout << "Enter computer speed: ";
	cin >> speed;

	cout << "Enter computer RAM: ";
	cin >> ram;

	cout << "Enter computer HDD: ";
	cin >> hdd;

	Computer computer1(speed, ram, hdd);

	cout << computer1.GetSpeed() << endl;
	cout << computer1.GetRam() << endl;
	cout << computer1.GetHdd() << endl;

	cout << "Enter laptop speed: ";
	cin >> speed;

	cout << "Enter laptop RAM: ";
	cin >> ram;

	cout << "Enter laptop HDD: ";
	cin >> hdd;

	cout << "Enter laptop battery time: ";
	cin >> batteryTime;

	cout << "Enter laptop weight: ";
	cin >> weight;

	Laptop laptop1(speed, ram, hdd, batteryTime, weight);

	cout << laptop1.GetSpeed() << endl;
	cout << laptop1.GetRam() << endl;
	cout << laptop1.GetHdd() << endl;
	cout << laptop1.GetBatteryTime() << endl;
	cout << laptop1.GetWeight() << endl;

	Compare(computer1, laptop1);
}