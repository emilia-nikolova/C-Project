#pragma once
#ifndef MYLIST_H
#define MYLIST_H

#include<fstream>
#include<iostream>
#include "Node.h"

class MyList {
private:
	Node* pFirst;
	Node* pLast;
public:
	Node* pEmpty;
	int emptyCount;
	MyList();
	~MyList();
	void insertNode(int, char);
	void SetDataBodyForElement(int id, char *fname, char *mname, char *lname, char* hstreet, char* hcity, char *hcountry, int hposcode, int bussyphone, int hophone, int mobphone1, int mobphone2, char *emaddr1, char *emaddr2);
	void releaseNode(int, char);
	void releaseList();
	void sortList();
	Node* smallestID();
	void SearchList();
	void displayElement(int id);
	int ListLength();
	void printList();
	friend void FileRead(char* file_name);
	friend void FileWrite(char* file_name);
};

const int maxDepth = 100;
int counter = 0;
Node* firstElement = new Node();

MyList::MyList() {      // creating an empty list
	pFirst = NULL;
	pLast = NULL;
	pEmpty = firstElement;
	emptyCount = counter;
}

MyList::~MyList() {
	Node* i;
	Node* j;
	for (i = pFirst; i != NULL; i = i->nextNode) {
		delete i;
	}
	for (j = firstElement; j != NULL; j = j->nextNode) {
		delete j;
	}
}

bool EmptyStack() {
	if (counter <= 0) {
		return true;
	}
	else {
		return false;
	}
}


void pushToStack(Node* n) {
	if (counter < maxDepth) {
		if (!EmptyStack()) {
			n->nextNode = firstElement;
			firstElement = n;
		}
		else {
			firstElement = n;
		}
		++counter;
	}
	else {
		std::cout << "Stack overflow!" << std::endl;
	}
}

Node* popEl; // popped Element

void pop() {
	Node* temp=new Node();
	if (!EmptyStack()) {
		std::cout << "You popped element with ID:" << std::endl;
		//firstElement->display();
		temp = firstElement;
		firstElement = firstElement->nextNode;
		popEl = temp;
		--counter;
		//delete temp;
		popEl->display();
	}
	else {
		std::cout << "Empty Stack!" << std::endl;
	}
	popEl->nextNode = NULL;
}



void MyList::insertNode(int a, char position) {
	Node* inserted;
	if (!EmptyStack()) {
		pop();
		inserted = popEl;
		inserted->setID(a);  //inserting new element from stack
	}
	else {
		inserted = new Node();
		inserted->setID(a);
	}
	if (position == 'h') {
		Node* temp;
		if (pFirst == NULL) {                         // case: empty list
			pFirst = inserted;
			pLast = inserted;
		}
		else if (pFirst->nextNode == NULL) {
			pLast = pFirst;
			pFirst = inserted;
			pFirst->nextNode = pLast;
		}
		else {
			temp = pFirst;
			pFirst = inserted;
			pFirst->nextNode = temp;
		}
	}
	else if (position == 'e') {
		if (pFirst == NULL) {                    // case: empty list
			pFirst = inserted;
			pLast = inserted;
		}
		else if (pFirst->nextNode == NULL) {           // case: second element in list
			pLast = inserted;
			pFirst->nextNode = pLast;
		}
		else {
			pLast->nextNode = inserted;
			pLast = inserted;
		}
	}
	else if (position == 'm') {
		Node* p;
		Node* d;
		Node* temp2;

		if (pFirst == NULL) {                  // case: empty list
			pFirst = inserted;
			pLast = inserted;
		}
		else if (pFirst->nextNode == NULL) {          // case: only 1 element in list
			if (inserted->pid < pFirst->pid) {
				temp2 = pFirst;
				pFirst = inserted;
				pLast = temp2;
				pFirst->nextNode = pLast;
			}
			else {
				pLast = inserted;
				pFirst->nextNode = pLast;
			}
		}
		else if (inserted->pid < pFirst->pid) {              // case: insert as first element, non-empty list
			temp2 = pFirst;
			pFirst = inserted;
			pFirst->nextNode = temp2;
		}
		else if (inserted->pid == pFirst->pid) {              // case: id equal to first, non-empty list
			inserted->nextNode = pFirst->nextNode;
			pFirst->nextNode = inserted;
		}
		else if ((inserted->pid > pLast->pid) || (inserted->pid == pLast->pid)) {            // case:  insert as a last element
			pLast->nextNode = inserted;
			pLast = inserted;
		}
		else {                                                                                 // case: insert in the middle
			for (p = pFirst; p->getNext() != NULL && p->pid < inserted->pid; p = p->getNext());
			if (pFirst->nextNode->nextNode == NULL) {                                          // case: second element in a non-empty list
				if (pFirst->pid < inserted->pid) {
					pFirst->nextNode = inserted;
					inserted->nextNode = pLast;
				}
			}
			else if (p->pid == pLast->pid) {                                            // case:: insert before last
				for (d = pFirst; d->nextNode->nextNode != NULL; d = d->getNext());
				d->nextNode = inserted;
				inserted->nextNode = pLast;
			}
			else {
				if (p->pid > inserted->pid) {
					for (d = pFirst; d->nextNode->pid < inserted->pid; d = d->getNext());
					d->nextNode = inserted;
					inserted->nextNode = p;
				}
				else {
					inserted->nextNode = p->nextNode;
					p->nextNode = inserted;
				}
				
			}
		}
	}
}

void MyList::SetDataBodyForElement(int id, char *fname, char *mname, char *lname, char* hstreet, char* hcity, char *hcountry, int hposcode, int bussyphone, int hophone, int mobphone1, int mobphone2, char *emaddr1, char *emaddr2) {
	Node* p;
	Node* d;
	for (p = pFirst; p != NULL; p = p->getNext()) {
		for (d = pFirst; d->pid != id; d = d->getNext());
		d->SetDataBody(fname, mname, lname, hstreet, hcity, hcountry, hposcode, bussyphone, hophone, mobphone1, mobphone2, emaddr1, emaddr2);
	}
	
}


void MyList::releaseNode(int a, char position) {
	Node* p;
	Node* d;
	if (pFirst == NULL) {                                         // case: empty list
		std::cout << "No elements in the list!" << std::endl;
	}
	else {
		if (position == 'h') {
			pushToStack(pFirst);
			if (pFirst->nextNode == NULL) {
				pFirst = NULL;
				pLast = NULL;
			}
			else if (pFirst->nextNode->nextNode == NULL) {
				pFirst = pFirst->nextNode;
				pLast = pFirst->nextNode;
			}
			else {
				pFirst = pFirst->nextNode;
			}
			
		}
		else if (position == 'e') {
			if (pFirst->nextNode == NULL) {
				pushToStack(pLast);
				pFirst = NULL;
				pLast = NULL;
			}
			else if (pFirst->nextNode->nextNode == NULL) {
				pushToStack(pLast);
				pFirst->nextNode = NULL;
				pLast = pFirst;
			} else {
				for (p = pFirst; p->nextNode->nextNode != NULL; p = p->getNext());
				pushToStack(pLast);
				p->nextNode = NULL;
				pLast = p;
			}
			//pushToStack(pLast);
			
		}
		else if (position == 'm') {

			if (a == pFirst->pid) {
				                                            // case: deleting first element
				if (pFirst->nextNode == NULL) {                             // case: 1 element in list
					pushToStack(pFirst);
					 pFirst=NULL;
					 pLast = NULL;
				}
				else {                                                    // case: more elements in list
					pushToStack(pFirst);
					pFirst = pFirst->nextNode;
					if (pFirst->nextNode == NULL) {                          // case: two elements in list
						pLast = pFirst;
					}
				}
			}
			else if (a == pLast->pid) {                                        // case: deleting last element
				pushToStack(pLast);
				for (p = pFirst; p->nextNode->nextNode != NULL; p = p->getNext());
				if (pFirst->nextNode->nextNode == NULL) {                      // case: last element in a 2-element list
					pFirst->nextNode = NULL;
					pLast = pFirst;
				}
				else {
					p->nextNode = NULL;
					pLast = p;
				}
			}
			else {
				for (p = pFirst; p->pid != a && p != NULL; p = p->getNext());
				if (p->pid != a) {
					std::cout << "No such element!" << std::endl;
				}
				for (d = pFirst; d->nextNode->pid != a; d = d->getNext());
				pushToStack(p);
				d->nextNode = p->nextNode;
				p=NULL;
			}
		}
		
	}
}

void MyList::releaseList() {
	Node* p;
	Node* temp;
	for (p = pFirst; p != NULL; p = p->getNext()) {
		temp = new Node();
		temp=p;
		temp = NULL;
	}
	pFirst = NULL;
	pLast = NULL;
	p = NULL;
}

/*
void MyList::sortList() {                                                    // bubble sort 
	Node* p;
	Node* temp;
	if (pFirst != NULL && pFirst->nextNode != NULL) {
		for (p = pFirst; p->getNext() != NULL; p = p->getNext()) {
			if (p->pid == pFirst->pid) {
				if (pFirst->nextNode->pid < pFirst->pid) {
					temp = pFirst;
					pFirst = pFirst->nextNode;
					pFirst->nextNode = temp;
				}
				else {
					continue;
				}
			}
			else {
				if (p->nextNode->pid < p->pid) {
					temp = p;
					p = p->nextNode;
					p->nextNode=temp;
				}
			}
		}
	}
	else {
		std::cout << "There are no enough elements to sort!" << std::endl;
		}
	}
}
*/

Node* MyList::smallestID() {
	Node* p;
	Node* smallestNode = pFirst;
	for (p = pFirst->getNext(); p != NULL; p = p->getNext()) {
		if (smallestNode->pid > p->pid) {
			smallestNode = p;
		}
	}
	return smallestNode;
}

/*
void MyList::SearchList() {
	char* data_field = new char();
	char* fieldContent = new char();
	MyString* data_Field;
	Node* p;
	MyString* fName = new MyString("FirstName");
	MyString* mName = new MyString("MiddleName");
	cout << "Enter searched data field:" << endl;
	cin >> data_field;
	data_Field = new MyString(data_field);
	cout << "Enter searched field content:" << endl;
	cin >> fieldContent;
	MyString* field_content = new MyString(fieldContent);
	for (p = pFirst; p != NULL; p = p->getNext()) {
		if (fName->isEqual(data_Field)) {
			if ((p->FirstName->isEqual(field_content))==true) {
				p->display();
				break;
			}
			else {
				continue;

			}
		}
		else if(data_field == "MiddleName"){
			if (field_content->isEqual(p->MiddleName)) 
			{
				p->display(); break;
			}
			else {
				continue;
			}
		}
		else {
			cout << "No such element";
		}
	}
}
*/

void MyList::displayElement(int id) {
	Node* p;
	//Node* d;
	for (p = pFirst; p != NULL; p = p->getNext()) {
		if (p->pid == id) {
			p->display();
		}
	}
}

int MyList::ListLength() {
	int counter = 0;
	Node* p;
	for (p = pFirst; p != NULL; p = p->getNext()) {
		counter++;
	}
	return counter;
}

void MyList::printList() {
	Node* p;
	if (pFirst != NULL) {
		for (p = pFirst; p != NULL; p = p->getNext()) {
			std::cout << "Element with id: " << p->pid << std::endl;
		}
	}
	else {
		std::cout << "Empty List!" << std::endl;
	}
	
}



#endif