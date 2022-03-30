#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>
using namespace std;

#define N 100

class MyString {
private:
	char* content=new char();
public:
	MyString();
	MyString(char* text);
	~MyString();
	void SetData(char* data);
	void Assign(MyString* s);
	int GetLength();
	void InputString();
	bool isEqual(MyString* s);
	void printString();
};

MyString::MyString() {
	content[0] = '\0';
}

MyString::MyString(char* text) {
	content = text;
}

MyString::~MyString() {
	delete content;
}

void MyString::SetData(char* data) {
	content = data;
}

void MyString::Assign(MyString* s) {
	content = s->content;
}

int MyString::GetLength() {
	int counter = 0;
	for (int i = 0; content[i] != '\0'; i++) {
		counter++;
	}
	return counter;
}

void MyString::InputString() {
	char* input = new char();
	std::cout << "Enter string" << std::endl;
	std::cin >> input;
	content = input;
}

bool MyString::isEqual(MyString* s) {
	if (content == s->content) {
		return true;
	}
	else {
		return false;
	}
}

void MyString::printString() {
	cout << content<<endl;
}


#endif
