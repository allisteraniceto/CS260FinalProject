#pragma once
#include "account.h"
#include "linkedlist.h"

class accountlist : public linkedlist<account> {
private:
	string filename;

};

//do later: save accounts onto a linked list file system
