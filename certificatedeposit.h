#include "account.h"
#pragma once
class certicatedeposit :public account
{
private:
	int duration;//3, 6, 12 duration of months

public:
	certicatedeposit():account()
	{
		duration = 0;
	}

	certicatedeposit(int accountid, long double balance, int accounttype,int duration) : account(accountid, balance, accounttype)
	{
		this->duration = duration;
	}

	long double CalculateInterest(long double balance)
	{
		
	/*	time_t t = time(0);
		struct tm * now = localtime(&t);
		datetime currentdt(now->tm_mon, now->tm_mday, now->tm_year, now->tm_hour, now->tm_min, now->tm_sec);*/
		
		if (balance > 0.0)
		{
			switch (duration)
			{
				case 3:
					return balance*INT_CD1;
					break;
				case 6:
					return balance*INT_CD2;
					break;
				case 12:
					return balance*INT_CD3;
					break;
				default:
					throw "duration of account does not match";
					break;
			}
		}
		return 0.0;
	}

	long double CalculatePenalty(long double balance)
	{
		/*time_t t = time(0);
		struct tm * now = localtime(&t);
		datetime currentdt(now->tm_mon, now->tm_mday, now->tm_year, now->tm_hour, now->tm_min, now->tm_sec);
		datetime beg = this->getdatetime();
		datetime span = currentdt - beg;
		if (duration==3&&(span.getyear>0||span.getmonth>11))
			return balance*0.5;
		if (duration==2&&(span.getyear>0 || span.getmonth>5))
			return balance*0.3;
		if (duration==1&&(span.getyear>0 || span.getmonth>2))
			return balance*0.10;*/
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