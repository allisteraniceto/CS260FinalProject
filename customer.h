#pragma once
#include <iostream>
#include <cstring>
#include "accountlist.h"

const int NAME_LENGTH = 50;

using namespace std;
class customer
{
private:
	long int customerid;
	//int account;
	accountlist* accptr;
	char fname[NAME_LENGTH];
	char lname[NAME_LENGTH];
	int fnlength;
	int lnlength;
	
public:
	customer() {
		customerid = 00000000;
		//account = 0; //default; 0-saving account
		fname[NAME_LENGTH-1] = { 'x' }; //-1 because of \n character at the end
		lname[NAME_LENGTH-1] = { 'x' };
		fnlength = 0;
		lnlength = 0;
		accptr = 0;
	}
	customer(long int customerid, string fname, string lname) {
		this->customerid = customerid;
		strcpy_s(this->fname, fname.c_str()); //copys parameter name into name member variable
		strcpy_s(this->lname, lname.c_str());
		this->fnlength = fname.length() + 1; //+1 becuase of the /0 at the end
		this->lnlength = lname.length() + 1; //+1 becuase of the /0 at the end
	}
	customer(long int customerid, string fname, string lname, accountlist* accptr) {
		this->customerid = customerid;
		strcpy_s(this->fname, fname.c_str()); //copys parameter name into name member variable
		strcpy_s(this->lname, lname.c_str());
		this->fnlength = fname.length() + 1; //+1 becuase of the /0 at the end
		this->lnlength = lname.length() + 1; //+1 becuase of the /0 at the end
		this->accptr = accptr;
	}

void setcustomerid(long int id)
{
	this->customerid = id;
}
//void setaccount(int account) {
//	this->account = account;
//}
//converts string into char*
void setfname(string fname){
	strcpy_s(this->fname, fname.c_str());
	this->fnlength = fname.length() + 1; //+1 becuase of the /0 at the end
}
//converts last name string into char array
void setlname(string lname) {
	strcpy_s(this->lname, lname.c_str());
	this->lnlength = lname.length() + 1; //+1 becuase of the /0 at the end
}
long int getcustomerid()
{
	return customerid;
}
//int getaccount() {
//	return account;
//}
char* getfname() {
	return fname;
}
char* getlname() {
	return lname;
}
int getlnlength() {
	return lnlength;
}
void printid()
{
	cout << customerid << endl;
}
void printCustomerInfo() {
	cout << "ID: " << customerid << endl;
	//if (account == 0) //if account = 0, it is a savings account
	//	cout << "Savings" << endl;
	//else if (account == 1)//if account = 1, it is a checking account
	//	cout << "Checking" << endl;
	//else if (account == 2)//if account = 2, it is a CD account
	//	cout << "CD" << endl;

	cout << "Name: ";
	//print first name
	for (int i = 0; i < fnlength;i++) {
		cout << fname[i];
	}
	cout << " ";
	//prints last name
	for (int i = 0; i < lnlength; i++) {
		cout << lname[i];
	}
	cout << endl;

	//print accounts connected to specific customer
	cout << "Accounts: " << endl;
	accptr->printCustomerAccounts(customerid);
	cout << "*******************" << endl;
}
int numCustPrompt() {
	int count;
	cout << "How many customers would you like to enter? ";
	cin >> count;
	return count;
}
void noNode() {
	cout << "NO NODE!!";;
}
};