#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include<iostream>
#include<conio.h>

class LinkedList {
	struct Node {
		int id;
		char* name;
		Node* next;
	}*head;
	int findLength(const char*);     //To find the correct length of the char before heap allocation -O(n)
public:
	LinkedList();                    //Default Constructor -O(1)
	LinkedList(int&,char*);          //Copy Constructor -O(1)
	~LinkedList();                   //Destructor -O(n)
	
	void menu();                     //Displays an interface for the user to interact with
	void display() const;			 //To diplay all the contents in the linked list		 -O(n)
	void create();                   //To create a new node in the linked list				 -O(1)
	int max() const;                 //Returns the maximum number in the linked list	  	 -O(n)
	int min() const;				 //Returns the minimum number in the linked list		 -O(n)
	void push(int&,char*);           //Adds a new Node to the end of the linked list		 -O(n)
	int countNodes() const;			 //Returns the amount of nodes in the linked list		 -O(n)
	int sumOfElements() const;       //Returns the sum of all ids in the linked list		 -O(n)
	void insert(int&);			     //Adds a record before the given index					 -O(n)
	void deleteNode(int&);           //Deletes a node at a specific index in the linked list			  -O(n)
	void pop();                      //Deletes a node at the end of the linked list						   -O(n)
	void reverse();                  //Reverses the entire linked list									   -O(n)
	bool check_sort();               //Returns a bool determining whether the linked list is sorted or not -O(n)

	//----------------------All search algorithms have move to head improvement in them------------------------
	
	char* linear_search(int&);        //Displays the name in correspondence with the given id -O(n)
	int linear_search(const char*);   //Displays the id in correspondence with the given name -O(n)  
	
};

#endif // !LINKED_LISTS_H