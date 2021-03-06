#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class CurrencyRate
{
private:
	int hour;

	double fx;

public:
	CurrencyRate()  // конструктор по подразбиране
	{
		hour = 0;

		fx = 0;
	}

	CurrencyRate(int hourParam, double fxParam) // експлицитен
	{
		hour = hourParam;
		fx = fxParam;
	}

	CurrencyRate(const CurrencyRate& currencyRateParam) // копиращ
	{
		hour = currencyRateParam.hour;
		fx = currencyRateParam.fx;
	}

	int GetHour()
	{
		return hour;
	}

	void SetHour(int hourParam)
	{
		hour = hourParam;
	}

	double GetFx()
	{
		return fx;
	}

	void SetFx(double fxParam)
	{
		fx = fxParam;
	}

	bool operator<(CurrencyRate &currencyRateParam)
	{
		return hour < currencyRateParam.hour;
	}

	bool operator+(CurrencyRate &currencyRateParam)
	{
		return fx + currencyRateParam.fx;
	}

	bool operator-(CurrencyRate &currencyRateParam)
	{
		return fx - currencyRateParam.fx;
	}
};

istream& operator>>(istream &stream, CurrencyRate &currencyRateParam)
{
	int hourParam;
	double fxParam;

	stream >> hourParam;
	stream >> fxParam;

	currencyRateParam.SetHour(hourParam);
	currencyRateParam.SetFx(fxParam);

	return stream;
}

ostream& operator<<(ostream &toStream, CurrencyRate &currencyRateParam)
{
	toStream << "Hour: " << currencyRateParam.GetHour() << endl;
	toStream << "FX: " << currencyRateParam.GetFx() << endl;

	return toStream;
}

class CurrencyRateRecord
{
private:
	string date;

	vector<CurrencyRate> currencyRates;

public:
	CurrencyRateRecord(string fileName)
	{
		ifstream readFile;

		readFile.open(fileName);

		if (!readFile)
		{
			cout << "File not Found." << endl;
		}
		//else 
		//{
		//	readFile >> *this;
		//}
	}

	CurrencyRateRecord(vector<CurrencyRate> currencyRatesParam)
	{
		currencyRates = currencyRatesParam;
	}

	CurrencyRateRecord()
	{

	}

	string GetDate()
	{
		return date;
	}

	void SetDate(string dateParam)
	{
		date = dateParam;
	}

	vector<CurrencyRate> GetCurrencyRates()
	{
		return currencyRates;
	}

	void SetCurrencyRates(vector<CurrencyRate> currencyRatesParam)
	{
		currencyRates = currencyRatesParam;
	}

	vector<double> vectorWithElementsSubstraction()
	{
		vector<double> substractionVector;

		for (int i = 1; i < currencyRates.size(); i++)
		{
			double substraction = currencyRates[i].GetFx() - currencyRates[i - 1].GetFx();
			substractionVector.push_back(substraction);
		}

		return substractionVector;
	}

	double MultiplySum(double number)
	{
		double sum = 0;

		for (int i = 1; i < currencyRates.size(); i++)
		{
			double substraction = currencyRates[i].GetFx() - currencyRates[i - 1].GetFx();
			sum += substraction;
		}

		return number * sum;
	}
};

istream& operator>>(istream &stream, CurrencyRateRecord &currencyRateRecordParam)
{
	vector<CurrencyRate> currencyRates;

	string dateParam;
	stream >> dateParam;
	currencyRateRecordParam.SetDate(dateParam);

	for (int i = 0; i < 3; i++)
	{
		CurrencyRate currencyRateParam;
		stream >> currencyRateParam;
		currencyRates.push_back(currencyRateParam);
	}

	currencyRateRecordParam.SetCurrencyRates(currencyRates);

	return stream;
}

ostream& operator<<(ostream &toStream, CurrencyRateRecord &currencyRateRecordParam)
{
	toStream << "Date: " << currencyRateRecordParam.GetDate() << endl;

	for (int i = 0; i < currencyRateRecordParam.GetCurrencyRates().size(); i++)
	{
		toStream << currencyRateRecordParam.GetCurrencyRates()[i] << endl;
	}

	return toStream;
}

void main()
{
	try {
		//CurrencyRateRecord currencyRateRecord_i("fileName.txt");

		CurrencyRateRecord currencyRateRecord;
		cin >> currencyRateRecord;
		cout << "- - - - - - - - - - - - - -" << endl;
		cout << currencyRateRecord;

		int sumElementsSubstractionMultiplication = currencyRateRecord.MultiplySum(5);
		cout << sumElementsSubstractionMultiplication << endl;
	}
	catch (exception error)
	{
		cout << error.what() << endl;
	}
}