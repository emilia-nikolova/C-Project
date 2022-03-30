#pragma once

#ifndef NODE_H
#define NODE_H

#include<iostream>
#include "MyString.h"
using namespace std;

class Node {
private:
	int id;
public:

	int &pid = id;
	Node *nextNode;
	MyString* FirstName = new MyString();
	MyString *MiddleName = new MyString();
	MyString *LastName = new MyString();
	MyString *HomeStreet = new MyString();
	MyString *HomeCity = new MyString();
	MyString *HomeCountry = new MyString();
	int HomePostalCode;
	int BussinessPhone;
	int HomePhone;
	int MobilePhone;
	int MobilePhone_2;
	MyString *EmailAddress = new MyString();
	MyString *EmailAddress_2 = new MyString();

	Node();
	Node(int a);
	~Node();
	void setID(int a);
	void SetDataBody(char* fname, char *mname, char* lname, char *hstreet, char *hcity, char *hcountry, int hposcode, int bussyphone, int hophone, int mobphone1, int mobphone2, char *emaddr1, char *emaddr2);
	Node* getNext();
	void setNext(Node* next);
	void display();
	//bool areEqual(Node* n);
};

Node::Node() {
	pid = 0;
	nextNode = NULL;
}

Node::Node(int a) {
	pid = a;
	nextNode = NULL;
}
Node::~Node() {
	pid = NULL;
	delete nextNode;
}

void Node::setID(int a) {
	pid = a;
}

void Node::SetDataBody(char *fname, char *mname,char *lname, char* hstreet, char* hcity, char *hcountry, int hposcode, int bussyphone, int hophone, int mobphone1, int mobphone2, char *emaddr1, char *emaddr2) {
	FirstName->SetData(fname);
	MiddleName->SetData(mname);
	LastName->SetData(lname);
	HomeStreet->SetData(hstreet);
	HomeCity->SetData(hcity);
	HomeCountry->SetData(hcountry);
	HomePostalCode = hposcode;
	BussinessPhone = bussyphone;
	HomePhone = hophone;
	MobilePhone = mobphone1;
	MobilePhone = mobphone2;
	EmailAddress->SetData(emaddr1);
	EmailAddress_2->SetData(emaddr2);
}

void Node::setNext(Node* next) {
	nextNode = next;
}

Node* Node::getNext() {
	return nextNode;
}

/*bool Node::areEqual(Node* n) {
	if(pid==n->pid )
}*/

void Node::display() {
	cout << pid << endl;
	FirstName->printString();
	cout << BussinessPhone<<endl;
	EmailAddress_2->printString();
}

#endif

