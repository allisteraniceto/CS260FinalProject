 #pragma once

//NEED TO STORE: when a transaction happens is date, account, customer, debit or credit

class transaction{
public:
	long int time; //epoch value
	int accountID; 
	int customerID;

	transaction() {
		time = 0;
		accountID = 0;
		customerID = 0;
	}
	int getAccountID() {
		return accountID;
	}
	void print() {
		cout << time << endl;
	}
};

struct CompareTime {
	bool operator()(transaction const& p1, transaction const& p2) {
		//return "true" if "p1" is ordered
		return p1.time < p2.time;
	}
};