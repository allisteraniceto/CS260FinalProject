#include "account.h"
#pragma once
class savings : public account
{
public:
	savings():account()
	{}

	savings(int accountid, long double balance, int accounttype): account(accountid,balance,accounttype)
	{}

	long double CalculateInterest(long double balance)
	{
		if (balance > 0.0)
			return balance + balance*INT_SAVINGS;
		return 0.0;
	}

	long double CalculatePenalty(long double balance)
	{
		if (balance < 1000.00)
			return 50.00;
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