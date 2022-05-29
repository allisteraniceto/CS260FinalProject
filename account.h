#include "datetime.h"
#include <time.h> //used to get struct "time_t" to get month, day, year, hour, min, seconds
#include <iostream>
#include <fstream>

using namespace std;
#pragma once
class account
{
private:
	long int accountid;
	long double balance;
	int accounttype;//0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket
	datetime activedate;

public:
	//"instead of using virtual function, have save and load inside accountlist"
	//virtual long double CalculateInterest(long double balance) = 0;
	//virtual long double CalculatePenalty(long double balance) = 0;
	//virtual void save(ofstream &out) = 0;
	//virtual void load(ifstream &in) = 0;

	const double INT_CHECKING = 0.02;
	const double INT_SAVINGS = 0.10;
	const double INT_CD1 = 0.25;
	const double INT_CD2 = 0.3;
	const double INT_CD3 = 0.5;
	const double INT_MMDA = 0.125;

	account()
	{
		time_t t = time(0);
		struct tm * now = localtime_s(&t);
		accountid = 0;
		balance = 0.00;
		accounttype = 0;
		activedate.set(now->tm_mon, now->tm_mday, now->tm_year, now->tm_hour, now->tm_min, now->tm_sec);
	}

	account(int accountid,long double balance,int accounttype)
	{
		time_t t = time(0);
		struct tm * now = localtime(&t);
		this->accountid = accountid;
		this->balance = balance;
		this->accounttype = accounttype;
		activedate.set(now->tm_mon, now->tm_mday, now->tm_year, now->tm_hour, now->tm_min, now->tm_sec);
	}

	int gettype()
	{
		return accounttype;
	}

	int getid()
	{
		return accountid;
	}

	void Debit(long double amount)
	{
		balance -= amount;
		//balance-=CalculatePenalty();
	}

	void Credit(long double amount)
	{
		balance += amount;
	}

	void setdatetime(int month, int day, int year, int hour, int minute, int second)
	{
		activedate.set(month, day, year, hour, minute, second);
	}
	
	datetime getdatetime()
	{
		return this->activedate;
	}

	void print(void)
	{
		cout << "Account:" << accountid << endl;
		cout << "Account Type:";
		if (accounttype == 0)
			cout << "Savings" << endl;
		else if (accounttype == 1)
			cout << "Checking;" << endl;
		else if (accounttype == 2)
			cout << "CD" << endl;
		else if (accounttype == 3)
			cout << "Money Market:" << endl;
		else
			throw "unexpected account type";
		cout << "Balance:" << balance << endl;
		cout << "Active Date:" << activedate.getmonth() << "/" << activedate.getday() << "/" << activedate.getyear() << endl << endl;

	}
};