#pragma once
#include <iostream>
using namespace std;

//can be made as a template
//template <class T>
//add <T> and T everywhere you create a node (e.g. node<T>*)
template <class T>
class node
{
private:
	T data;
	node<T>* next; //self instantiation, point to the next node
	node<T>* prev; //points to the previous node (makes it a "doubly" linked list)
public:
	node() {
		data = T(); //syntax for intializing w/ template
		next = 0; //set equal to zero so it point to nowhere (for now)
		prev = 0;
	}
	void setData(T data) {
		this->data = data;
	}
	T getData() {
		return data;
	}
	void setNext(node<T>* next) {
		this->next = next;
	}
	node* getNext() {
		return this->next;
	}
	void setPrev(node<T>* prev) {
		this->prev = prev;
	}
	node* getPrev() {
		return this->prev;
	}
};

template <class T>
class linkedlist{
protected:
	node<T>* head;
	node<T>* tail; //now has a ptr that points to the end of the list
	int count;
public:
	linkedlist() {	//initializes private member funcs
		head = 0;
		tail = 0;
		count = 0; //count of how many nodes are on the list
	}

	//deconstructor to delete list
	~linkedlist() {
		for (int i = 0; i < count; i++)
			this->removefront();
	}
	node<T>* getHead() {
		return head;
	}
	//adds a node to the front of the linked list
	void addfront(T data) {
		//node* ntemp is on the stack, so it get destroyed (just a reference)
		node* ntemp = new node<T>(); //new node() is on the heap
		ntemp->setData(data);
		if (head == 0) {
			head = ntemp;
			tail = ntemp;
			count++; //keeps track of how many nodes are on the list
		}
		else {
			//make next and prev links FIRST, then link head LAST
			ntemp->setNext(head); //setting the next ptr to point to next node
			//ntemp->next=head; (this is used if next was public:)
			head->setPrev(ntemp); //setting the prev ptr to point to previous node
			//head->prev=ntemp; (this is used if prev was public:)
			head = ntemp; //ntemp points the head already, so its making the head ptr point to the new head
			count++;
		}
	}

	//removes the first node of the linked list
	void removefront()
	{
		if (head == 0)
		{
			return;
		}
		else
		{
			node<T>* ntemp; //creates a temp ptr
			ntemp = head; //temp ptr point to head
			head = head->getNext(); //sets head ptr to point to the new head
			head->setPrev(0); //previous points to nowhere
			delete ntemp; //delete aht address ntemp point to;
			count--;
		}
	}

	//adds a node to the back of the linked list
	void addrear(T data)
	{
		node<T>* ntemp = new node<T>();
		ntemp->setData(data);
		if (head == 0)
		{
			head = ntemp;
			tail = ntemp;
			count++;
		}
		else
		{
			//instead of adding a head, add a rear (use tail)
			ntemp->setPrev(tail);
			//ntemp->prev=tail
			tail->setNext(ntemp);
			//tail->next=ntemp;
			tail = tail->getNext();
			count++;
		}
	}

	//removes the last node of the linked list
	void removerear()
	{
		if (head == 0) {
			return;
		}
		else {
			node<T>* temp = tail;
			tail = tail->getPrev(); //making tail ptr point to previous node
			//tail=tail->prev
			tail->getNext()->setNext(0); //sets next ptr to point to 0 (to nowwhere)
			//tail->next=next
			delete temp; //deletes the address of the node (deleting the node)
			count--;
		}
	}

	//inserts a new node in between 2 existing nodes
	void insertat(T data, int index) {
		//if no node has been created, creates a new one
		if (head == 0) {
			head = new node<T>();
			head->setData(data);
			count++;
		}
		else {
			if (index < 1) {
				addfront(data);
			}
			else if (index >= count) {
				addrear(data);
			}
			else {
				node<T>* temp = head; //temporary ptr to the head
				node<T>* nnode = new node<T>(); //creates new node to be inserted
				nnode->setData(data); //sets data to the new node
				for (int i = 0; i < index - 1; i++) //points to the new node seqeuntially (next node to the next)
					temp = temp->getNext();
				nnode->setNext(temp->getNext()); //new node points to the next node
				nnode->setPrev(temp); //new node points to previous node
				temp->setNext(nnode); //sets previous node to point the new node
				nnode->getNext()->setPrev(nnode); //sets next node's previous to point to the new node
				count++;
			}
		}
	}
	void removeAt(int index) {
		if (head == 0) {
			return 0;
		}
		else {
			if (index < 1) {
				removefront();
			}
			else if (index >= count) {
				removerear();
			}
			else {
				node<T>* temp = head;

				for (int i = 0; i < index - 1; i++)
					temp = temp->getNext();

				node<T>* todelete = temp->getNext();
				temp->setNext(todelete->getNext());
				todelete->getNext()->setPrev(temp);
				delete todelete;
				count--;
			}
		}
	}
	T getat(int index) {
		if (head == 0)
			return T(); //dummy return value
		node<T>* temp = head;
		for (int i = 0; i < index; i++)
			temp = temp->getNext();
		return temp->getData();
	}
	//replace the data @ specific index with different data
	//using for bubble sort 
	void setdataAt(int index, T val) {
		if (head == 0)
			return;
		node<T>* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->getNext();
		}
		temp->setData(val);
	}

	//count accessor
	int getcount() {
		return count;
	}
	void print() {
		node<T>* temp = head;
		while (temp != 0) {
			//first we ouput the head of linked list data (first node)
			cout << temp->getData() << endl;
			//head = head->next();
			temp = temp->getNext(); //temp ptr points to next ptr which points to address of the next node value
		}
	}
};