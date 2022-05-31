#pragma once
#include "account.h"
#include "linkedlist.h"
#include <fstream>

class accountlist : public linkedlist<account> {
public:
	void writeFile(string filename) {
		int count = this->getcount();
		ofstream ofs(filename, ios::binary);
		ofs.write((char*)(&count), sizeof(int));

		node<account>* temp = head;
		while (temp != 0)
		{
			//temp->getData().print();//ofs.write((char*)(&temp), sizeof(customer));
			temp = temp->getNext();
		}
		ofs.close();
	}
	//function to read the file
	void loadFile(string filename) {
		int count = 0;
		account temp;
		ifstream ifs(filename, ios::binary);

		//ifs.seekg(0); // to make sure that the data is read from the starting position of the file

		ifs.read((char*)(&count), sizeof(int));

		for (int i = 0; i < count; i++) {
			ifs.read((char*)(&temp), sizeof(account));
			this->addrear(temp);
		}
		ifs.close();
	}
	void readFile(string filename)
	{
		int count = 0;
		account temp;
		ifstream ifs(filename, ios::binary);

		ifs.read((char*)&count, sizeof(int));

		for (int i = 0; i < count; i++) {
			ifs.read((char*)(&temp), sizeof(account));
			this->addrear(temp);
		}
		ifs.close();
	}
	void addAccount(string filename) {
		//temp variables to put in account object parameters
		long int accountid=0;
		long double balance=0;
		int accounttype=0;//0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket
		datetime activedate;

		cout << "Enter account ID: ";
		cin >> accountid;
		cout << "Enter Balance: ";
		cin >> balance;
		cout << "Enter Account Type (0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket): ";
		cin >> accounttype;

		account acc(accountid, balance, accounttype); //temp acccount object for storing
		this->loadFile(filename);
		this->addrear(acc);
		this->writeFile(filename);
	}
	void removeAccount(string filename) {

		int rnum = 0;
		cout << "enter account to delete:";//prompt user to enter specific customer to delete
		cin >> rnum;

		this->loadFile(filename); //load file onto the list;
		this->removeAt(rnum - 1); //remove specific record (*index=rnum-1)
		this->writeFile(filename); //write the file to the filename PROBLEM HERE

		//could show all accounts customer has w/ record# in the beginning 
		//then ask user to enter record# to delete specific account
	}

};

//do later: save accounts onto a linked list file system
