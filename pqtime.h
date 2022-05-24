#pragma once
#include "linkedlist.h";
#include "transaction.h";

class pqtime : public linkedlist<transaction>{
public:
    void push(transaction item)
    {
        this->addrear(item);
    }
    transaction pop() {
        transaction item = this->getat(0);
        this->removefront();
        return item;
    }
    transaction top() {
        return this->getat(0);
    }
    //sorts transactions by epoch value time
    void sort() {
        node<transaction>* temp = head;
        transaction ttemp;
        for (int i = 0; i < this->getcount(); i++) {
            for (int j = 0; j < this->getcount() - 1; j++) {
                if (this->getat(j).time > this->getat(j + 1).time) { //changed < to > so: earliest time to latest time
                    ttemp = getat(j);
                    this->setdataAt(j, this->getat(j + 1));
                    this->setdataAt(j + 1, ttemp);
                }
            }
            temp = temp->getNext();
        }
    }
};

