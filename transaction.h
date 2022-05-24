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
	transaction(long int time, int accountID, int customerID) {
		this->time = time;
		this->accountID = accountID;
		this->customerID = customerID;
	}
	int getAccountID() {
		return accountID;
	}
	void printT() {
		cout << "account ID: " << accountID << endl;
		cout << "time: " <<  time << endl;
	}

};

struct CompareTime {
	bool operator()(transaction const& p1, transaction const& p2) {
		//return "true" if "p1" is ordered
		return p1.time < p2.time;
	}
};