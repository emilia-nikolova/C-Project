# C++ Project
A C++ course project

The purpose of this project is to create custom made classes for String and List instead of the ones defined in C++ libraries.  
This solution contains three header files: MyString.h, Node.h, MyList.h.
All three classes contain the following methods: default constructor, constructor with a parameter and destructor.

Note:  To see more clearly how the individual methods work, one should better comment some of the other methods in Main.cpp while a single method is tested.

Class MyString (MyString.h)
  The MyString class has an attribute char* content and contains the following methods:
  -	void SetData(char* data) – assigns the value of data to content
  -	void Assign(MyString* s) – assigns the content of other object of type MyString to the content of the current object
  -	int GetLength() – returns the number of characters in the variable content
  -	void InputString();
  -	bool isEqual(MyString* s) – compares the content of the current object with the content of s and if they are equal, returns true
  -	void printString() – prints the value of content

Class Node (Node.h)
  Class Node has a private attribute id and public attributes: pid that is a reference to id, FirstName, MiddleName, LastName, HomeStreet, HomeCity, HomeCountry,             EmailAddress   and EmailAddress_2, which are of type MyString. Other public attributes are HomePostalCode, BussinessPhone, HomePhone, MobilePhone, MobilePhone_2, these     are of type int. It   also has an attribute nextNode of type Node.
  Methods of the class:
  -	void setID(int a) – sets the id of the node
  -	void SetDataBody(char* fname, char *mname, char* lname, char *hstreet, char *hcity, char *hcountry, int hposcode, int bussyphone, int hophone, int mobphone1, int               mobphone2, char *emaddr1, char *emaddr2) – assigns values to all attributes except from id and nextNode
  -	Node* getNext() – returns nextNode
  -	void setNext(Node* next) – sets nextNode
  -	void display() – displays the id of the node and some of its attributes of types int and MyString. * I do not display all attributes in this method, but it can be done

Class MyList (MyList.h)
  This class has two attributes of type Node = pFirst and pLast. It also has the following methods:
  -	void insertNode(int, char) – inserts a node with id of type int. The variable char can take values ‘h’ for head, ‘m’ for middle and ‘e’ for end. Depending on these         three values the node is inserted in a particular place. 
  -	void SetDataBodyForElement(int id, char *fname, char *mname, char *lname, char* hstreet, char* hcity, char *hcountry, int hposcode, int bussyphone, int hophone, int         mobphone1, int mobphone2, char *emaddr1, char *emaddr2) – calls the method SetDataBody from the Node class for the node with id equal to the value given as a parameter     by the call of the method
  -	void releaseNode(int, char) – removes the node with the given id from the list
  -	void releaseList() – empties the list
  -	Node* smallestID() – returns the node with the smallest id from the list
  -	void displayElement(int id) – calls the display method for the node with the given id
  -	int ListLength() – returns the length of the list
  -	void printList() – prints the ids of all elements in the list

Main.cpp
  -	void FileRead(char* file_name) – It reads data from a csv file (data-fields.csv) and displays it on the screen
  -	void FileWrite(char* file_name) – Writes data in a csv file (output_data.csv)
