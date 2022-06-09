#include "account.h"
#pragma once
class checking :public account
{
public:
	checking():account()
	{}

	checking(int accountid, int customerid, long double balance, int accounttype) : account(accountid, customerid, balance, accounttype)
	{}

	long double CalculateInterest(long double balance)
	{
		if (balance > 0.0)
			return balance + balance*INT_CHECKING;
		return 0.0;
	}

	long double CalculatePenalty(long double balance)
	{
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