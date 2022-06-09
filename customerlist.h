#pragma once
#include "linkedlist.h"
#include "customer.h"
#include <fstream>

class customerlist : public linkedlist<customer> {
	//write to file function
public:
	void writefile(string filename){

		int count = this->getcount(); //access count from parent class
		ofstream ofs(filename, ios::binary); //create output file object
		ofs.write((char*)(&count), sizeof(int)); //writes count to file

		node<customer>* temp = head; //pointer to first customer object
		customer ctemp; //temporary customer to write

		//traverse the list and write to file
		while (temp != 0) {
			ctemp = temp->getData();
			ofs.write((char*)(&ctemp), sizeof(customer)); //temp->getData().print() to test it
			//BEFORE: we were writing the pointer "temp" to the file NOW: we are writing a "ctemp" customer object to file
			temp = temp->getNext();
		}
		ofs.close();
	}

	//function to read the file
	void loadFile(string filename) {
		int count = 0;
		customer temp;
		ifstream ifs(filename, ios::binary);

		//ifs.seekg(0); // to make sure that the data is read from the starting position of the file

		ifs.read((char*)(&count), sizeof(int));

		for (int i = 0; i < count; i++) {
			ifs.read((char*)(&temp), sizeof(customer));//PROBLEM!!! (PROBLEM FIXED :])
			this->addrear(temp);
		}
		ifs.close();
	}

	//function to add/remove a node
	void editRecord(string filename)
	{
		int count = 0;
		int rnum = 0;
		int id = 0;
		customer temp;
		fstream inoutfile(filename, ios::in | ios::out | ios::binary);
		inoutfile.read((char*)&count, sizeof(int));
		cout << "enter record to change:";
		cin >> rnum;

		//for (int i = 0; i < count; i++) {
		//	inoutfile.read((char*)(&temp), sizeof(customer));//PROBLEM!!! (PROBLEM FIXED :])
		//	this->addrear(temp);
		//}

		//inoutfile.seekg (0, ios::beg);
		inoutfile.seekg(4 + sizeof(customer) * (rnum - 1), ios::beg);//add 4 bytes for header multy sizeof customer by rnum;
		inoutfile.read((char*)(&temp), sizeof(customer));
		cout << "Record Number:" << rnum << " " << "Customer id of" << temp.getcustomerid() << endl;
		cout << "Enter new ID: ";
		cin >> id;
		temp.setcustomerid(id);
		//1042 +4
		inoutfile.seekp(4 + sizeof(customer) * (rnum - 1), ios::beg);//add 4 bytes for header multy sizeof customer by rnum;
		inoutfile.write((char*)(&temp), sizeof(customer));
		inoutfile.close();
	}

	//add a customer
	void addcustomer(string filename) {
		long int id = 0; 
		int account = 0;
		char* fname = nullptr; 
		fname = new char[NAME_LENGTH]; //allocate memory for char array

		char* lname = nullptr;
		lname = new char[NAME_LENGTH]; //allocate memory for char array

		string name;
		cin.ignore(); //ignore \n character
		cout << "Enter first name: " << endl; //prompt user to enter name for new record
		cin.getline(fname, NAME_LENGTH);
		cout << "Enter first name: " << endl; //prompt user to enter name for new record
		cin.getline(lname, NAME_LENGTH);
		cout << "Enter new ID: " << endl; //prompt user to enter id for new record
		cin >> id;
		/*cout << "Enter type of account (0-Savings, 1-Checking, 2-CD, 3-Money Market): ";
		cin >> account;*/

		customer temp(id, fname, lname); //set id and person's name by using overloaded constructor

		this->loadFile(filename); //load file onto the list
		this->addrear(temp); //add new record onto the list
		this->writefile(filename); //write the file to the filename
	
		delete[] fname, lname; //free the memory
	}
	void removecustomer(string filename) {

		int rnum = 0;
		cout << "enter record to delete:";//prompt user to enter specific customer to delete
		cin >> rnum;

		this->loadFile(filename); //load file onto the list;
		this->removeAt(rnum-1); //remove specific record (*index=rnum-1)
		this->writefile(filename); //write the file to the filename PROBLEM HERE

		//could show all customers in w/ record# in the beginning 
		//then ask user to enter record# to delete specific customer
	}

	//print ALL customer objects
	void printcustomer() {
		node<customer>* temp = head;
		customer ctemp;
		while (temp != 0) {
			//first we ouput the head of 1linked list data (first node)
			ctemp = temp->getData();
			ctemp.printCustomerInfo();
			//head=head->next();
			temp = temp->getNext(); //temp ptr points to next ptr which points to address of the next node value
		}
	}

	//sort function (for later)
	void sort() { 

	}

};

