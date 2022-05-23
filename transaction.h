 #pragma once

class transaction {
public:
	long int time; //epoch value
	int accountID;
	int customerID;
};

struct CompareTime {
	bool operator()(transaction const& p1, transaction const& p2) {
		//return "true" if "p1" is ordered
		return p1.time < p2.time;
	}
};