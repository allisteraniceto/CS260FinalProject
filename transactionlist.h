/*
GOALS:
- revise editRecord()
*/
#pragma once
#include "pqtime.h"
#include "transaction.h";
#include <fstream>

//linked list of transactions
class transactionlist : public pqtime {
public:
	/*void writeFile(string filename){
		int count = this->getcount();
		ofstream ofs(filename, ios::binary);
		ofs.write((char*)(&count), sizeof(int));

		node<transaction>* temp = head;
		while (temp != 0)
		{
			ofs.write((char*)(&temp), sizeof(transaction));
			temp = temp->getNext();
		}
		ofs.close();
	}*/
	void writeFile(string filename) {

		int count = this->getcount(); //access count from parent class
		ofstream ofs(filename, ios::binary); //create output file object
		ofs.write((char*)(&count), sizeof(int)); //writes count to file

		node<transaction>* temp = head; //pointer to first customer object
		transaction ctemp; //temporary customer to write

		//traverse the list and write to file
		while (temp != 0) {
			ctemp = temp->getData();
			ofs.write((char*)(&ctemp), sizeof(transaction)); 
			temp = temp->getNext();
		}
		ofs.close();
	}
	void readFile(string filename)
	{
		int count = 0;
		transaction temp;
		ifstream ifs(filename, ios::binary);

		ifs.read((char*)&count, sizeof(int));

		for (int i = 0; i < count; i++){
			ifs.read((char*)(&temp), sizeof(transaction));
			this->addrear(temp);
		}

		ifs.close();
	}
	void editRecord(string filename){
		int count = 0;
		int rnum = 0;
		int id = 0;
		transaction temp;
		fstream inoutfile(filename, ios::in | ios::out | ios::binary);

		inoutfile.read((char*)&count, sizeof(int));

		cout << "enter record to change:";
		cin >> rnum;
		//inoutfile.seekg(0, ios::beg);
		inoutfile.seekg(4 + sizeof(transaction) * (rnum - 1), ios::beg);//add 4 bytes for header multy sizeof customer by rnum;
		inoutfile.read((char*)(&temp), sizeof(transaction));

		//??????????????????????????? REVISE FROM HERE ??????????????????????????????
		cout << "Record Number:" << rnum << " " << "Customer id of" << temp.getAccountID() << endl;
		cout << "Enter new ID:";
		cin >> id;
		//temp.setid(id);												  //104 * 2 +4
		inoutfile.seekp(4 + sizeof(transaction) * (rnum - 1), ios::beg);//add 4 bytes for header multy sizeof customer by rnum;
		inoutfile.write((char*)(&temp), sizeof(transaction));
		inoutfile.close();
	}
	//print transaction objects
	void printcustomer() {
		node<transaction>* temp = head;
		transaction ctemp;
		while (temp != 0) {
			//first we ouput the head of 1linked list data (first node)
			ctemp = temp->getData();
			ctemp.printT();
			//head=head->next();
			temp = temp->getNext(); //temp ptr points to next ptr which points to address of the next node value
		}
	}
};