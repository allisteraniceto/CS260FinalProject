#include "account.h"
#pragma once
class moneymarket :public account
{
public:
	moneymarket() :account()
	{}

	moneymarket(int accountid, long double balance, int accounttype):account(accountid,balance,accounttype)
	{}

	long double CalculateInterest(long double balance)
	{
		if (balance > 0.0)
			return balance*0.125;
		return 0.0;
	}

	long double CalculatePenalty(long double balance)
	{
		if (balance < 10000.00)
			return 200.00;
		return 0.0;
	}

	void save(ofstream &out)
	{
		out.write((char*) this, sizeof(*this));
	}

	void load(ifstream &in)
	{
		in.read((char*)this, sizeof(*this));
	}
};