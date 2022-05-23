#pragma once
#include <iostream>
#include <cstring>

const int NAME_LENGTH = 50;

using namespace std;
class customer
{
private:
	int id;
	char fname[NAME_LENGTH];
	char lname[NAME_LENGTH];
	int fnlength;
	int lnlength;
	
public:
	customer() {
		id = 0;
		fname[NAME_LENGTH-1] = { 'x' }; //-1 because of \n character at the end
		lname[NAME_LENGTH-1] = { 'x' };
		fnlength = 0;
		lnlength = 0;
	}
	customer(int id, string fname, string lname) {
		this->id = id;
		strcpy_s(this->fname, fname.c_str()); //copys parameter name into name member variable
		strcpy_s(this->lname, lname.c_str());
		this->fnlength = fname.length() + 1; //+1 becuase of the /0 at the end
		this->lnlength = lname.length() + 1; //+1 becuase of the /0 at the end
	}

void setid(int id)
{
	this->id = id;
}
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
int getid()
{
	return id;
}
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
	cout << id << endl;
}
void printCustomerInfo() {
	cout << "ID: " << id << endl;
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