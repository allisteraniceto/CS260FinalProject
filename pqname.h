#pragma once
#include <queue>

#include "linkedlist.h";
#include "customer.h";

class pqname : public linkedlist<customer> {
public:
    void push(customer item)
    {
        this->addrear(item);
    }
    customer pop() {
        customer item = this->getat(0);
        this->removefront();
        return item;
    }
    customer top() {
        return this->getat(0);
    }
    
    //example from class (DOESNT WORK)
    void sort() {
        customer temp;
        char lastone[NAME_LENGTH];
        char lasttwo[NAME_LENGTH];
        //bubble sort
        for (int i = 0; i < this->getcount(); i++) {
            for (int j = 0; j < this->getcount(); j++) {
                strcpy_s(lastone, this->getat(j).getlname()); //copy last name onto temporary char array
                strcpy_s(lasttwo, this->getat(j+1).getlname()); //copy last name in next element onto temporary char array

                //upper case first name and last name to get correct values
                for (int r = 0; r < strlen(lastone); r++) {
                    lastone[r] = toupper(lastone[r]);
                }
                for (int r = 0; r < strlen(lastone); r++) {
                    lasttwo[r] = toupper(lasttwo[r]);
                }
                            //index                     //index + 1 (next element)
                if (strcmp(this->getat(j).getlname(),this->getat(j+1).getlname()) < 0)
                temp = getat(j);
                this->setdataAt(j, this->getat(j + 1));
                this->setdataAt(j + 1, temp);
            }
        }
    }

    //my implementation(not the most efficient but works...)
    void sortTwo() {
        //temp variables
        customer temp;
        char lastone[NAME_LENGTH];
        char lasttwo[NAME_LENGTH];
        char* last1;
        char* last2;
        int length1;
        int length2;


        //bubble sort
        for (int i = 0; i < this->getcount(); i++) {
            for (int j = 0; j < this->getcount()-1; j++) {
                length1 = this->getat(j).getlnlength(); //length of last name of index
                length2 = this->getat(j + 1).getlnlength(); //length of last name of index + 1
                last1 = this->getat(j).getlname(); //sets lname char array ptr to temp ptr
                last2 = this->getat(j + 1).getlname(); //again for index + 1

                //set last name = to lastone temp char array so it doesnt chang the value in the linked list
                for (int x = 0; x < length1; x++) {
                    lastone[x] = last1[x];
                }
                for (int x = 0; x < length2; x++) {
                    lasttwo[x] = last2[x];
                }
                
                //upper case first name and last name to get correct values
                for (int r = 0; r < length1; r++) {
                    lastone[r] = toupper(lastone[r]);
                }
                for (int r = 0; r < length2; r++) {
                    lasttwo[r] = toupper(lasttwo[r]);
                }
                //index                     //index + 1 (next element)
                if (strcmp(this->getat(j).getlname(), this->getat(j + 1).getlname()) > 0) {
                    temp = getat(j);
                    this->setdataAt(j, this->getat(j + 1));
                    this->setdataAt(j + 1, temp);
                }
            }
        }
    }

    //print customer objects
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
};

//lets try ordering in alphabetical order (using ASCII)?
//lowest ASCII value 

//strcmp: compares the first char in string and returns
//        -1: less than, 1: greater than, 0: equal (from left to right)


//ideas:
//-convert char array to string, then compare
//-set char* to temp char* and make the temp equal to lastone and lasttwo