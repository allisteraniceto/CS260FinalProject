/*
Programmer: Allister Aniceto
Purpose: CS260 Final Project
Date Modified: 5/22/22
Compiler: VS C++ 2019
*/

/*
UNDERSTANDING:
-PHASE 1:
	#transaction class that inherits from pqueue list "transaction.h" !DONE!
	#saving a list of transctions "transactionlist.h" !DONE!
	#update UML diagram

-PHASE 2:
	#implement linked list so data (e.g. customers, accounts, transactions) are structured and stored as a linked list
	#add these:
		Add accounts
		Add customers
		Remove accounts
		Remove customers
		Print customers by last name with accounts
		Process transactions sorted by time (epoch value, one large number)

-customer HAS many accounts
-account HAS 3 types of accounts 


GOALS TO ACHIEVE:
-finish transaction.h
	#figure out and implement "epoch" time !DONE!

-revise transactionlist.h
	#load and save transactions (use load and save from customerlist.h) !DONE!
	#revise: editRecord()

-add customer, then customer list-> !DONE!
-add account, then account list (convert to linked list)->
-make transaction, then transaction list (convert to linked list)


-fix calculatePenalty() in certificate deposit

-delete .dat file before program ends
*/

#include <iostream>
#include "customerlist.h"
#include "linkedlist.h"
#include "pqname.h"
#include "transaction.h"
#include "transactionlist.h"
#include <ctime> //time since Jan 1, 1970
using namespace std;

//menu for write or load
void menu() {
	cout << endl;
	cout << "*--------------------------------------------------------*\n";
	cout << "|0. Exit                                                 |\n";
	cout << "|1. Enter ALL Customer Information                       |\n";
	cout << "|2. Read ALL Customer Information                        |\n";
	cout << "|3. Edit a record                                        |\n";
	cout << "|4. Add a customer                                       |\n";
	cout << "|5. Print customer by last name                          |\n";
	cout << "|6. Make a transaction                                   |\n";
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
	while (choice >= 0 && choice <= 6) { //while loop for menu based system
		switch (choice) {
		case 0:
			return 0;
		case 1: //enter all customer info
			custNum = temp.numCustPrompt();
			for (int i = 0; i < custNum; i++) {
				int tempID = 0;

				string tempfirst;
				string templast;
				cout << "Enter ID for record #" << i + 1 << ": ";
				cin >> tempID;
				cin.ignore();
				cout << "Enter first name: ";
				cin >> tempfirst;
				cout << "Enter last name: ";
				cin >> templast;
				temp.setid(tempID);
				temp.setfname(tempfirst);
				temp.setlname(templast);
				custlist.addrear(temp);
			}
			custlist.writefile("customer.dat");
			break;
		case 2: //read all customer info
		{
			customerlist reading;
			reading.loadFile("customer.dat");
			//custlist.printcustomer();
			for (int i = 0; i < reading.getcount(); i++) {
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
		//Ch8 challenge
		case 5: //print customers in last name order
		{
			pqname order;
			customer one(28, "kevin", "durant");
			customer two(24, "kobe", "bryant");
			customer three(30, "steph", "curry");
			customer four(23, "lebron", "james");

			order.push(one);
			order.push(two);
			order.push(three);
			order.push(four);
			order.sortTwo();
			order.printcustomer();
			break;
		}
		case 6: //PHASE 1: (will edit soon...)
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
