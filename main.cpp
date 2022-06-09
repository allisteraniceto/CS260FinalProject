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
		Remove accounts (removeAccount func inside accountList) !DONE!
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
	#PRINT CUSTOMERS W/ ACCOUNT (somehow link accounts and customers inside customer.h when printing) !DONE!
	#deposit and withdrawal inside account.h
	#add/link account to customer- so that when customer is printed, account associated with customer will print as well

-fix calculatePenalty() in certificate deposit
-delete .dat file before program ends
-implement .dat files into main

-SOMETHING WRONG w/ removing the last node from the linked list!!!!
	#removerear function ????

-SOMETHING WRONG!!
	#when displaying all customer info, all counts are shown from .dat file
-link customer and account together
*/

#include <iostream>
#include "customerlist.h"
#include "linkedlist.h"
#include "pqname.h"
#include "transaction.h"
#include "transactionlist.h"
#include "accountlist.h"
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
	cout << "|6. Make a transaction                                   |\n";
	cout << "|7. Print transactions                                   |\n";
	cout << "|8. Add customer w/ accounts and print by last name      |\n";
	cout << "|9. Print all accounts                                   |\n";
	cout << "*--------------------------------------------------------*" << endl;
}

int main(void) {
	int choice=0;
	int custNum=0;
	customerlist custlist; //customer list to store
	accountlist acclist; //account list to store
	transactionlist translist; //transaction list to store
	customer temp; //temp customer object to store customer info
	
	menu();	//output menu
	cout << "Enter a choice: "; //prompt user to enter a choice
	cin >> choice;
	while (choice >= 0 && choice <= 9) { //while loop for menu based system
		switch (choice) {
		case 0:
			return 0;
		case 1: //enter all customer info
			custNum = temp.numCustPrompt();
			for (int i = 0; i < custNum; i++) {
				int tempID = 0;

				string tempfirst;
				string templast;
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
				//temp.setaccount(tempacc);
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
		case 6: //PHASE 1: (will edit again...)
		{
			transactionlist translist;
			time_t currenttime = 0; //temp value to hold time
			currenttime = time(NULL);
			transaction trans1(currenttime, 39203, 1);
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

			translist.writeFile("transactions.dat");

			//translist.printcustomer();
			break;
		}
		//PHASE 2
		case 7:
		{
			transactionlist load;
			load.readFile("transactions.dat");
			load.printcustomer();
			break;
		}
		//1st - add customers w/ account
		case 8: //print customers w/ customer info in last name order
		{
			pqname order; //priorty queue for last names
			
			//make types of accounts w/ customerid attached

			checking ch(1234, 28, 500000, 1); //checking(int accountid, int customerid, long double balance, int accounttype)
			savings sav(4321, 24, 25.00, 0);
			certicatedeposit cd(3456, 24, 20000, 2, 3);
			moneymarket mm(2938, 24, 10000, 3);
			accountlist alist;

			//add accounts to the account list

			alist.addAccount(&ch);
			alist.addAccount(&sav);
			alist.addAccount(&cd);
			alist.addAccount(&mm);

			alist.writeFile("accounts.dat");

			customer one(28, "kevin", "durant", &alist); //customer(long int customerid, string fname, string lname)
			customer two(24, "kobe", "bryant", &alist);
			customer three(30, "steph", "curry", &alist);
			customer four(23, "lebron", "james", &alist);

			order.push(one);
			order.push(two);
			order.push(three);
			order.push(four);
			order.sortTwo();
			order.printcustomer();
			break;
		}
		//2nd - load customers and print()
		case 9: //print customers w/ customer info in last name order
		{
			accountlist load;
			cout << "accounts: " << endl;
			load.loadFile("accounts.dat");
			load.printAllAccounts();
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
