/*
Programmer: Allister Aniceto
Purpose: CS260 Final Project
Date Modified: 5/24/22
Compiler: VS C++ 2019
*/

/*
UNDERSTANDING:
-PHASE 1:
	#transaction class that inherits from pqueue list "transaction.h" !DONE!
	#saving a list of transctions "transactionlist.h" !DONE!
	#update UML diagram !DONE!

-PHASE 2:
	#implement linked list so data (e.g. customers, accounts, transactions) are structured and stored as a linked list !DONE!
	#add these:
		Add accounts !DONE!
		Add customers !DONE!
		Remove accounts (removeAccount func inside accountList) 
		Remove customers (removeCustomer func inside customerList) !DONE!
		Print customers by last name with accounts !DONE!
		Process transactions sorted by time (epoch value, one large number) !DONE!
	#customerlist, accountlist, and transactionlist.h all have seperate .bin files

-customer HAS many accounts
-account HAS 3 types of accounts 

-when making a new account, an account object has a parameter for accountid (to link account w/ customer)

GOALS TO ACHIEVE:
-revise transactionlist.h
	#load and save transactions (use load and save from customerlist.h) !DONE!
	#revise: editRecord()

-add:
	#removeAccount to accountlist 
	#removeCustomer to customerlist !DONE!
	#deposit and withdrawal inside account.h

-fix calculatePenalty() in certificate deposit
-delete .dat file before program ends
-implement .dat files into main

-SOMETHING WRONG w/ removing the last node from the linked list!!!!
	#removerear function ????

-link customer and account together
*/

#include <iostream>
#include "customerlist.h"
#include "linkedlist.h"
#include "pqname.h"
#include "transaction.h"
#include "transactionlist.h"
#include <ctime> //time since Jan 1, 1970
using namespace std;

//hello
//menu for write or load
void menu() {
	cout << endl;
	cout << "*--------------------------------------------------------*\n";
	cout << "|0. Exit                                                 |\n";
	cout << "|1. Enter ALL Customer Information                       |\n";
	cout << "|2. Display ALL Customer Information                     |\n";
	cout << "|3. Edit a record                                        |\n";
	cout << "|4. Add a customer                                       |\n";
	cout << "|5. Remove a customer                                    |\n";
	cout << "|6. Print customer by last name                          |\n";
	cout << "|7. Make a transaction                                   |\n";
	cout << "*--------------------------------------------------------*" << endl;
}

int main(void) {
	int choice=0;
	int custNum=0;
	customerlist custlist; //customer list to store
	transactionlist translist; //transaction list to store
	customer temp; //temp customer object to store customer info
	
	menu();	//output menu
	cout << "Enter a choice: "; //prompt user to enter a choice
	cin >> choice;
	while (choice >= 0 && choice <= 7) { //while loop for menu based system
		switch (choice) {
		case 0:
			return 0;
		case 1: //enter all customer info
			custNum = temp.numCustPrompt();
			for (int i = 0; i < custNum; i++) {
				int tempID = 0;

				string tempfirst = NULL;
				string templast = NULL;
				int tempacc = 0;
				cout << "Enter ID for record #" << i + 1 << ": ";
				cin >> tempID;
				cin.ignore();
				cout << "Enter first name: ";
				cin >> tempfirst;
				cout << "Enter last name: ";
				cin >> templast;
				cout << "Enter type of account (0-Savings, 1-Checking, 2-CD, 3-Money Market): ";
				cin >> tempacc;
				temp.setcustomerid(tempID);
				temp.setaccount(tempacc);
				temp.setfname(tempfirst);
				temp.setlname(templast);
				custlist.addrear(temp);
			}
			custlist.writefile("customer.dat");
			break;
		case 2: //display all customer info
		{
			customerlist reading;
			reading.loadFile("customer.dat");
			//custlist.printcustomer();
			for (int i = 0; i < reading.getcount(); i++) {
				cout << "-----------------------" << endl;
				cout << "- Record #" << i + 1 << ": -" << endl;
				cout << "-----------------------" << endl;
				temp = reading.getat(i);
				temp.printCustomerInfo();
			}
			//debug:
			//cout << "reading count: " << reading.getcount() << endl;
			//cout << "custlist count: " << custlist.getcount();
			break;
		}
		case 3: //edit a specific record
		{
			customerlist edit; //temp list to edit a record;
			edit.editRecord("customer.dat");
			break;
		}
		case 4: //add a customer to the list
		{
			customerlist add; //temp list to add a record
			add.addcustomer("customer.dat");
			break;
		}
		case 5://remove a customer from the list
		{
			customerlist print, remove;
			print.loadFile("customer.dat");
			//custlist.printcustomer();
			for (int i = 0; i < print.getcount(); i++) {
				cout << "-----------------------" << endl;
				cout << "- Record #" << i + 1 << ": -" << endl;
				cout << "-----------------------" << endl;
				temp = print.getat(i);
				temp.printCustomerInfo();
			}
			remove.removecustomer("customer.dat");

			break;
		}
		//Ch8 challenge
		case 6: //print customers in last name order
		{
			pqname order;
			customer one(28, 1, "kevin", "durant");
			customer two(24, 0, "kobe", "bryant");
			customer three(30, 2, "steph", "curry");
			customer four(23, 0,"lebron", "james");

			order.push(one);
			order.push(two);
			order.push(three);
			order.push(four);
			order.sortTwo();
			order.printcustomer();
			break;
		}
		case 7: //PHASE 1: (will edit again...)
		{
			time_t currenttime=0; //temp value to hold time
			currenttime = time(NULL);
			transaction trans1(currenttime, 39203,1);
			system("pause"); //little puase to have different time
			currenttime = time(NULL);
			transaction trans2(currenttime, 23902, 2);
			system("pause");
			currenttime = time(NULL);
			transaction trans3(currenttime, 339203, 3);
			
			translist.push(trans1);
			translist.push(trans2);
			translist.push(trans3);

			translist.sort();

			translist.printcustomer();
			break;
		}
		}
		menu();
		cout << "Enter a choice: ";
		cin >> choice;
		cout << endl;
	}
	cout << "goodbye" << endl;
	return 0;
}
