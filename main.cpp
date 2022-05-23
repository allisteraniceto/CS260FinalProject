/*
Programmer: Allister Aniceto
Purpose: CS260 Final Project
Date Modified: 5/21/22
Compiler: VS C++ 2019
*/

/*
GOALS TO ACHIEVE:
-make priority queue
-delete .dat file before program ends
*/

#include <iostream>
#include "customerlist.h"
#include "linkedlist.h"
#include "pqname.h"
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
	cout << "*--------------------------------------------------------*" << endl;
}

int main(void) {
	int choice=0;
	int custNum=0;
	customerlist custlist;
	//customerlist reading; // to read the data
	//customerlist edit; //temp list to edit data
	customer temp;
	
	menu();	//output menu
	cout << "Enter a choice: "; //prompt user to enter a choice
	cin >> choice;
	while (choice >= 0 && choice <= 5) { //while loop for menu based system
		switch (choice) {
		case 0:
			return 0;
		case 1: //enter all customer info
			custNum = temp.numCustPrompt();
			for (int i = 0; i < custNum; i++) {
				int tempID = 0;
				/*char tempfname[NAME_LENGTH];
				char templname[NAME_LENGTH];*/

				string tempfirst;
				string templast;
				cout << "Enter ID for record #" << i+1 << ": ";
				cin >> tempID;
				cin.ignore();
				cout << "Enter first name: ";
				/*cin.getline(tempfname, NAME_LENGTH);*/
				cin >> tempfirst;
				cout << "Enter last name: ";
				/*cin.getline(templname, NAME_LENGTH);*/
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
			customer temp;
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
		menu();
		cout << "Enter a choice: ";
		cin >> choice;
		cout << endl;
	}
	cout << "goodbye" << endl;
	return 0;
}

//add customer, then customer list->
//make account, then account list->
//make transaction, then transaction list

//add certificate deposit from samediffbank file