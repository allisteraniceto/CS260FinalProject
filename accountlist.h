#pragma once
#include "account.h"
#include "linkedlist.h"
#include "savings.h"
#include "checking.h"
#include "moneymarket.h"
#include "certificatedeposit.h"
#include <fstream>
#include <vector>

class accountlist : public linkedlist<account*> {
private:
	vector<int> accounttypes;
public:
	void writeFile(string filename) {
		int count = this->count; //getting count from the stack (instead of the heap)
		ofstream ofs(filename, ios::binary);
		ofs.write((char*)(&count), sizeof(int));

		for (int i = 0; i < count; i++) {
			ofs.write((char*)&accounttypes[i], sizeof(int));
		}

		account* acct = 0; 
		node<account*>* temp = head;
		for (int i = 0; i < count; i++)
		{
			acct = temp->getData();
			switch (accounttypes[i])//0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket
			{
			case 0:
				ofs.write((char*)acct, sizeof(savings));//104 bytes
				break;
			case 1:
				ofs.write((char*)acct, sizeof(checking));//104 bytes
				break;
			case 2:
				ofs.write((char*)acct, sizeof(certicatedeposit));//112 bytes
				break;
			case 3:
				ofs.write((char*)acct, sizeof(moneymarket));//104 bytes
				break;
			default:
				throw "error account type not found loading from file";
				break;
			}
			temp = temp->getNext();
		}

		//node<account*>* temp = head;
		//while (temp != 0)
		//{
		//	//temp->getData().print();//ofs.write((char*)(&temp), sizeof(customer));
		//	temp = temp->getNext();
		//}
		ofs.close();
	}
	//function to read the file
	void loadFile(string filename) {
		int count = 0;
		int itemp = 0;
		account *atemp;
		ifstream ifs(filename, ios::binary);

		//ifs.seekg(0); // to make sure that the data is read from the starting position of the file

		ifs.read((char*)(&count), sizeof(int)); //read amount of accounts in file
		for (int i = 0; i < count; i++) {
			ifs.read((char*)(&atemp), sizeof(int));
			accounttypes.push_back(itemp);
			//this->addrear(atemp); //SOMETHING WRONG HERE
		}
		node <account*>* ttemp = head;
		for (int i = 0; i < count; i++) {
			switch (accounttypes[i])//0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket
			{
			case 0:
				atemp = new savings();
				ifs.read((char*)atemp, sizeof(savings));
				break;
			case 1:
				atemp = new checking();
				ifs.read((char*)atemp, sizeof(checking));
				break;
			case 2:
				atemp = new certicatedeposit();
				ifs.read((char*)atemp, sizeof(certicatedeposit));
				break;
			case 3:
				atemp = new moneymarket();
				ifs.read((char*)atemp, sizeof(moneymarket));
				break;
			default:
				throw "error account type not found loading from file";
				break;
			}
			addAccount(atemp);
		}
		ifs.close();
	}
	//void readFile(string filename)
	//{
	//	int count = 0;
	//	account temp;
	//	ifstream ifs(filename, ios::binary);

	//	ifs.read((char*)&count, sizeof(int));

	//	for (int i = 0; i < count; i++) {
	//		ifs.read((char*)(&temp), sizeof(account));
	//		this->addrear(temp);
	//	}
	//	ifs.close();
	//}

	//void addAccount(string filename) {
	//	//temp variables to put in account object parameters
	//	long int accountid=0;
	//	long double balance=0;
	//	int accounttype=0;//0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket
	//	datetime activedate;

	//	cout << "Enter account ID: ";
	//	cin >> accountid;
	//	cout << "Enter Balance: ";
	//	cin >> balance;
	//	cout << "Enter Account Type (0 - Savings, 1 - Checking, 2 - CD, 3 - MoneyMarket): ";
	//	cin >> accounttype;

	//	account acc(accountid, balance, accounttype); //temp acccount object for storing
	//	this->loadFile(filename);
	//	this->addrear(acc);
	//	accounttypes.push_back(acc->gettype()) //THIS IS GOOD ALREADY, just need to edit other things
	//	this->writeFile(filename);
	//}

	void addAccount(account *paccount) {
		this->addrear(paccount);
		accounttypes.push_back(paccount->gettype()); //adds newly made account in the back of the vector
	}
	//void removeAccount(string filename) {

	//	int rnum = 0;
	//	cout << "enter account to delete:";//prompt user to enter specific customer to delete
	//	cin >> rnum;

	//	this->loadFile(filename); //load file onto the list;
	//	this->removeAt(rnum - 1); //remove specific record (*index=rnum-1)
	//	this->writeFile(filename); //write the file to the filename PROBLEM HERE

	//	//could show all accounts customer has w/ record# in the beginning 
	//	//then ask user to enter record# to delete specific account
	//}
	//THIS IS THE GOOD ONE
	void removeAccount(account* paccount) {
		node <account*>* temp = head;
		for (int i=0; i<this->count;i++) {
			if (paccount->getaccountid() == temp->getData()->getaccountid()) {
				this->removeAt(i);
			}
			temp = temp->getNext();
		}
	}

	//prints ALL accounts
	void printAllAccounts() {
		int i = 0;
		node<account*>* temp = head;
		while (temp != 0) {
			cout << "record #" << i << endl;
			cout << temp->getData()->getaccountid() << endl;
			temp = temp->getNext();
			i++;
		}
	}
	
	//print accounts of specific customer
	void printCustomerAccounts(int id) {
		node<account*>* temp = head;
		for (int i = 0; i < this->count; i++) {
			if (id == temp->getData()->getcustomerid()) {
				cout << temp->getData()->getaccountid() << endl;
			}
			temp = temp->getNext();
		}
	}


};

//do later: save accounts onto a linked list file system
