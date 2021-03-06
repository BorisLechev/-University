#include "pch.h"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class HeartRate
{
private:
	int serialMoment;
	int momentHeartRate;

public:
	HeartRate()  // конструктор по подразбиране
	{
		serialMoment = 0;
		momentHeartRate = 0;
	}

	HeartRate(int serialMomentParam, int momentHeartRateParam)  // експлицитен конструктор
	{
		serialMoment = serialMomentParam;
		momentHeartRate = momentHeartRateParam;
	}

	HeartRate(const HeartRate& heartRate)  // копиращ конструктор
	{
		serialMoment = heartRate.serialMoment;
		momentHeartRate = heartRate.momentHeartRate;
	}

	int GetSerialMoment()
	{
		return serialMoment;
	}

	void SetSerialMoment(int serialMomentParam)
	{
		serialMoment = serialMomentParam;
	}

	int GetMomentHeartRate()
	{
		return momentHeartRate;
	}

	void SetMomentHeartRate(int momentHeartRateParam)
	{
		momentHeartRate = momentHeartRateParam;
	}

	bool operator<(HeartRate heartRate)
	{
		return momentHeartRate < heartRate.momentHeartRate;
	}

	bool operator>(HeartRate heartRate)
	{
		return momentHeartRate > heartRate.momentHeartRate;
	}

	static bool compare(HeartRate firstHeartRate, HeartRate secondHeartRate)
	{
		firstHeartRate.momentHeartRate > secondHeartRate.momentHeartRate;
	}
};

istream& operator>>(istream &stream, HeartRate heartRate)
{
	int serialMomentParam;
	int momentHeartRateParam;

	stream >> serialMomentParam;
	stream >> momentHeartRateParam;

	heartRate.SetSerialMoment(serialMomentParam);
	heartRate.SetMomentHeartRate(momentHeartRateParam);

	return stream;
}

ostream& operator<<(ostream& toStream, HeartRate heartRate)
{
	toStream << "Serial moment: " << heartRate.GetSerialMoment() << endl;
	toStream << "Moment heart rate: " << heartRate.GetMomentHeartRate() << endl;

	return toStream;
}

class HeartRatesData
{
private:
	string patientName;

	list<HeartRate> heartRates;

public:
	HeartRatesData()   // конструктор по подразбиране
	{
		patientName = "";
	}

	HeartRatesData(string fileName)
	{
		ifstream readFile;
		readFile.open(fileName);

		if (!readFile)
		{
			cout << "File not found." << endl;
		}
		// else
		// {
		// 	readFile >> *this;     
		// }
	}

	string GetPatientName()
	{
		return patientName;
	}

	void SetPatientName(string patientNameParam)
	{
		patientName = patientNameParam;
	}

	list<HeartRate> GetHeartRates()
	{
		return heartRates;
	}

	void SetHeartRates(list<HeartRate> heartRatesParam)
	{
		heartRates = heartRatesParam;
	}

	static int countLowerThan(HeartRatesData heartRatesDataParam, int max)
	{
		list<HeartRate> heartRates = heartRatesDataParam.GetHeartRates();
		int counter = 0;

		for (int i = 0; i < heartRates.size(); i++)
		{
			list<HeartRate>::iterator heartRate = heartRates.begin();
			advance(heartRate, i);

			HeartRate currentHeartRate = *heartRate;

			if (currentHeartRate.GetMomentHeartRate() > max)
			{
				counter++;
			}
		}

		return counter;
	}

	static int counterHigherThan(HeartRatesData heartRatesDataParam, int min)
	{
		list<HeartRate> heartRates = heartRatesDataParam.GetHeartRates();
		int counter = 0;

		for (int i = 0; i < heartRates.size(); i++)
		{
			list<HeartRate>::iterator heartRate = heartRates.begin();
			advance(heartRate, i);

			HeartRate currentHeartRate = *heartRate;

			if (currentHeartRate.GetMomentHeartRate() < min)
			{
				counter++;
			}
		}

		return counter;
	}

	static int counterBetween(HeartRatesData heartRatesDataParam, int min, int max)
	{
		list<HeartRate> heartRates = heartRatesDataParam.GetHeartRates();
		int counter = 0;

		for (int i = 0; i < heartRates.size(); i++)
		{
			list<HeartRate>::iterator heartRate = heartRates.begin();
			advance(heartRate, i);

			HeartRate currentHeartRate = *heartRate;

			if (currentHeartRate.GetMomentHeartRate() < min && currentHeartRate.GetMomentHeartRate() > max)
			{
				counter++;
			}
		}

		return counter;
	}
};

istream& operator>>(istream &stream, HeartRatesData heartRatesDataParam)
{
	list<HeartRate> heartRates;
	string patientNameParam;

	stream >> patientNameParam;
	heartRatesDataParam.SetPatientName(patientNameParam);

	for (int i = 0; i < 11; i++)
	{
		HeartRate heartRateParam;
		stream >> heartRateParam;
		heartRates.push_back(heartRateParam);

	}

	heartRatesDataParam.SetHeartRates(heartRates);

	return stream;
}

ostream& operator<<(ostream &toStream, HeartRatesData &heartRatesDataParam)
{
	toStream << "Patient name: " << heartRatesDataParam.GetPatientName() << endl;

	list<HeartRate> heartRates = heartRatesDataParam.GetHeartRates();
	heartRates.sort();

	for (int i = 0; i < heartRates.size(); i++)
	{
		list<HeartRate>::iterator heartRate = heartRates.begin();
		advance(heartRate, i);

		toStream << *heartRate << endl;
	}

	return toStream;
}

void main()
{
	try {
		HeartRatesData heartRateData;
		cin >> heartRateData;

		cout << "- - - - - - - - - - - - - -" << endl;
		cout << heartRateData;


		/*
		HeartRatesData heartRateData_readFile("Ivan.txt");
		cin >> heartRateData_readFile;
		cout << "- - - - - - - - - - - - - -" << endl;
		cout << heartRateData_readFile;
		*/
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}