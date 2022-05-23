#pragma once;
class datetime
{
private:
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int second;

public:
	datetime()
	{
		month = 0;
		day = 0;
		year = 0;
		hour = 0;
		minute = 0;
		second = 0;
	}

	datetime(int month, int day, int year, int hour, int minute, int second)
	{
		this->month = month;
		this->day = day;
		this->year = year;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	void set(int month, int day, int year, int hour, int minute, int second)
	{
		this->month = month;
		this->day = day;
		this->year = year;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	int getyear()
	{
		return year;
	}

	int getmonth()
	{
		return month;
	}

	int getday()
	{
		return day;
	}

	int gethour()
	{
		return hour;
	}

	int getmin()
	{
		return minute;
	}

	int getsec()
	{
		return second;
	}

	datetime get()
	{
		return *this;
	}

	datetime operator-(datetime right)
	{
		datetime temp;
		/*temp.year = this->year - right.getyear;
		temp.month = this->month - right.month;
		temp.day = this->day - right.day;
		temp.hour = this->hour - right.hour;
		temp.minute = this->minute - right.minute;
		temp.second = this->second - right.second;*/
		return temp;
	}

	bool operator<(datetime right)
	{
		if (year < right.year)
		return true;
		else
		{
			if (month < right.month)
			return true;
			else
			{
				if (day < right.day)
				return true;
				else
				{
					if (hour < right.hour)
						return true;
					else
						if (minute < right.minute)
							return true;
						else
						{
							if (second < right.second)
								return true;
						}
				}
			}
		}
		return false;
	}
};