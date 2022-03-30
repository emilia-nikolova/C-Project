#include<iostream>
#include<fstream>
#include "Node.h"
#include "MyList.h"
#include "MyString.h"

using namespace std;

void FileRead(char* file_name) {
	char* data=new char[200];
	ifstream infile;
	infile.open(file_name, ios::in);
	bool is_open = infile.is_open();
	while (is_open) {              
		infile.getline(data, 200);
		cout << data;
	}
	infile.close();
}

void FileWrite(char* out_file_name) {
	char* data=new char[200];
	ofstream outfile;
	outfile.open(out_file_name, ios::out);
	bool is_open = outfile.is_open();
	cin.getline(data, 200);
	outfile << data << endl;
	cin.getline(data, 200);
	outfile << data << endl;
	outfile.close();

}

int main() {

	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	n1->SetDataBody("aaa", "aaa", "aaa", "aaa", "aaa", "aaa", 111, 111, 111, 111, 111,"aaa", "aaa");
	//n1->display();

	MyList* list = new MyList();
	list->insertNode(3, 'h');
	list->insertNode(2, 'm');
	list->insertNode(3, 'm');
	list->insertNode(7, 'e');
	list->insertNode(10, 'e');

	list->SetDataBodyForElement(3, "aaa", "aaa", "aaa", "aaa", "aaa", "aaa", 111, 111, 111, 111, 111, "aaa", "aaa");
	list->SetDataBodyForElement(7, "bbbb", "bbb", "bbb", "bbb", "bbb", "bbb", 222, 222, 222, 222, 222, "bbb", "bbb");
	list->displayElement(3);
	list->displayElement(7);
	
	list->releaseNode(2, 'h');
	list->releaseNode(0, 'e');

	
	//cout << list->ListLength();

	//FileRead("data-fields.csv");
	FileWrite("output_data.csv");


	//list->releaseList();

	//list->printList();
	//list->smallestID()->display();

} 





