#include "pch.h"
#include <iostream>
#include<string>
#include<vector>

using namespace std;

class Ticket
{
private:
	string station;

	double fare;

public:
	Ticket()
	{
		station = "";

		fare = 0;
	}

	Ticket(string stationParam, double fareParam)
	{
		station = stationParam;

		fare = fareParam;
	}

	string GetStation()
	{
		return station;
	}

	void SetStation(string stationParam)
	{
		station = stationParam;
	}

	double GetFare()
	{
		return fare;
	}

	void SetFare(double fareParam)
	{
		fare = fareParam;
	}

	int GetDistance()
	{
		if (fare < 2)
		{
			return 10;
		}

		else if (fare >= 2 && fare < 3)
		{
			return 20;
		}

		else if (fare >= 3 && fare < 5)
		{
			return 60;
		}

		else
		{
			return 100;
		}
	}

	friend istream& operator>>(istream &stream, Ticket ticket)
	{
		string stationInput;
		double fareInput;

		stream >> stationInput;
		stream >> fareInput;

		ticket.SetStation(stationInput);
		ticket.SetFare(fareInput);

		return stream;
	}

	bool operator<(Ticket ticket)
	{
		return fare < ticket.GetFare();
	}
};

class TicketCollection
{
private:
	vector<Ticket> tickets;

public:
	TicketCollection ticketCollection()
	{
		tickets;
	}

	void AddTicket(Ticket ticket)
	{
		tickets.push_back(ticket);
	}

	friend ostream& operator<<(ostream& toStream, TicketCollection ticketCollection)
	{
		toStream << "Ticket collection:" << endl;

		for (int i = 0; i < ticketCollection.tickets.size(); i++)
		{
			toStream << "Ticket data: " << ticketCollection.tickets[i].GetStation() << " " << ticketCollection.tickets[i].GetFare() << " lv. " << ticketCollection.tickets[i].GetDistance() << endl;
		}

		return toStream;
	}

	double GetSumOfFares()
	{
		double sum = 0;

		for (int i = 0; i < tickets.size(); i++)
		{
			sum += tickets[i].GetFare();
		}

		return sum;
	}

	double MostExpensiveTicket()
	{
		double currentTicket = 0;

		for (int i = 0; i < tickets.size(); i++)
		{
			if (currentTicket < tickets[i].GetFare())
			{
				currentTicket = tickets[i].GetFare();
			}
		}

		return currentTicket;
	}
};

void main()
{
	try
	{
		Ticket firstTicket("Sofia", 25.65);
		Ticket secondTicket("Dobrich", 3.31);
		Ticket thirdTicket("Plovdiv", 21.11);
		Ticket fourthTicket("Burgas", 10.23);
		Ticket fifthTicket("Pleven", 15.99);

		TicketCollection ticketCollection;

		ticketCollection.AddTicket(firstTicket);
		ticketCollection.AddTicket(secondTicket);
		ticketCollection.AddTicket(thirdTicket);
		ticketCollection.AddTicket(fourthTicket);
		ticketCollection.AddTicket(fifthTicket);

		cout << ticketCollection << endl;

		cout << "Most expensive ticket: " << ticketCollection.MostExpensiveTicket() << " lv." << endl;

		cout << "Sum: " << ticketCollection.GetSumOfFares() << " lv." << endl;
	}
	catch (const std::exception&)
	{
		cout << "Ohoooo imash greshka brat." << endl;
	}
}