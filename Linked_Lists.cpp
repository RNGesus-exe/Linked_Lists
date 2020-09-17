#include "Linked_Lists.h"

int LinkedList::findLength(const char* str)
{
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length+1;
}

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(int& id, char* name)
{
	if (head) {
		Node* temp = new Node;
		temp->id = id;
		temp->name = new char[findLength(name)];
		strcpy_s(temp->name, findLength(name), name);
		temp->next = nullptr;
		head->next = temp;
		temp = nullptr;
	}
	else {
		head = new Node;
		head->id = id;
		head->name = new char[findLength(name)];
		strcpy_s(head->name, findLength(name), name);
		head->next = nullptr;
	}
}

void LinkedList::menu()
{
	int choice;
	int id;
	char execution_pause;
	bool flag(true);
	do {
		char* name = new char[50];  //Will be optimized by the findLength() inside push()
		system("CLS");
		std::cout << "------------Welcome to Linked List Manager-----------"
			<< "\n1)  Create a new linked list"
			<< "\n2)  Display the records in the linked list"
			<< "\n3)  Add a new record to the end of the linked list"
			<< "\n4)  Display the amount of records in the linked list"
			<< "\n5)  Display the record with largest id"
			<< "\n6)  Display the record with the smallest id"
			<< "\n7)  Search and Display the name in correspondence to given id"
			<< "\n8)  Search and Display the id in correspondence to given name"
			<< "\n9)  Display the sum of all ids in the linked list"
			<< "\n10) Insert a record at a specific index of linked list"
			<< "\n11) Delete a record at a specific index of linked list"
			<< "\n12) Delete a record from the end of the linked list"
			<< "\n13) Reverse a linked list"
			<< "\n14) Check if linked list is sorted"
			<< "\n15) Exit";

		std::cout << "\nWhat do you want to do = ";
		std::cin >> choice;
		std::cin.ignore();

		switch (choice) {
			case 1:
				this->create();
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 2:
				this->display();
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 3:
				std::cout << "Enter id of student = ";
				std::cin >> id;
				std::cin.ignore();
				std::cout << "Enter the name of student = ";
				std::cin.getline(name, 50);
				this->push(id, name);
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 4:
				std::cout << "The total amount of records in the linked list are = " << this->countNodes() << '\n';
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 5:
				id = this->max();
				std::cout << "The record with the largest id = "<<this->linear_search(id)<<'\n';
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 6:
				id = this->min();
				std::cout << "The record with the smallest id = " << this->linear_search(id) << '\n';
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 7:
				std::cout << "Enter id of student = ";
				std::cin >> id;
				std::cout << "The name of student with this id is = " << this->linear_search(id) << '\n';
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 8:
				std::cout << "Enter name of student = ";
				std::cin.getline(name, 50);
				std::cout << "The id of student with this name is = " << this->linear_search(name) << '\n';
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 9:
				std::cout << "Sum of all ids = " << this->sumOfElements() << '\n';
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 10:
				std::cout << "Enter the index = ";
				std::cin >> id;
				this->insert(id);
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 11:
				std::cout << "Enter the index = ";
				std::cin >> id;
				this->deleteNode(id);
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 12:
				this->pop();
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 13:
				this->reverse();
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 14:
				if (check_sort()) {
					std::cout << "The linked list is sorted!!!\n";
				}
				else {
					std::cout << "The linked list is not sorted!!!\n";
				}
				std::cout << "Press any key to continue...\n";
				execution_pause = _getche();
				break;
			case 15:
				flag = false;
				break;
			default:
				std::cerr << "No such option exists!!!!\n";
				std::cerr << "Press any key to continue...\n";
				execution_pause = _getche();
		}
		delete[] name;      //To deallocate the heap allocated memory
	} while (flag);
}

void LinkedList::display() const
{
	Node* temp = head;
	while (temp) {
		std::cout << "\nStudent ID   = " << temp->id
			<< "\nStudent Name = " << temp->name
			<< "\n----------------------------------------\n";
		temp = temp->next;
	}
}

void LinkedList::create()
{
	int id;
	char* name = new char[50];  //Will be optimized by the findLength()
	std::cout << "Enter id of student = ";
	std::cin >> id;
	std::cin.ignore();
	std::cout << "Enter the name of student = ";
	std::cin.getline(name,50);
	if (head) {
		Node* temp = head;
		while (head) {
			head = head->next;
			delete[] temp->name;
			temp->name = nullptr;
			delete temp;
			temp = head;
		}
		//------------Deallocated old linked list heap memory to make new linked list
		head = new Node;
		head->id = id;
		head->name = new char[findLength(name)];
		strcpy_s(head->name, findLength(name), name);
		delete[] name;           //To delete the heap memory of name
		head->next = nullptr;
	}
	else {
		head = new Node;
		head->id = id;
		head->name = new char[findLength(name)];
		strcpy_s(head->name, findLength(name), name);
		delete[] name;           //To delete the heap memory of name
		head->next = nullptr;
	}
}

int LinkedList::max() const
{
	int max = INT32_MIN;
	if (head) {
		Node* temp = head;
		while (temp) {
			if (temp->id > max) {
				max = temp->id;
			}
			temp = temp->next;
		}
		return max;
	}
	else {
		return max;
	}
}

int LinkedList::min() const
{
	int min = INT32_MAX;
	if (head) {
		Node* temp = head;
		while (temp) {
			if (temp->id < min) {
				min = temp->id;
			}
			temp = temp->next;
		}
		return min;
	}
	else {
		return min;
	}
}

void LinkedList::push(int& id, char* name)
{
	if (head) {
		Node* temp = new Node;
		temp->id = id;
		temp->name = new char[findLength(name)];
		strcpy_s(temp->name, findLength(name), name);
		temp->next = nullptr;
		Node* holder = head;
		while (holder->next) {
				holder = holder->next;
		}
		holder->next = temp;
		temp = nullptr;
	}
	else {
		head = new Node;
		head->id = id;
		head->name = new char[findLength(name)];
		strcpy_s(head->name, findLength(name), name);
		head->next = nullptr;
	}
}

int LinkedList::countNodes() const
{
	int total_nodes = 0;
	Node* temp = head;
	while (temp) {
		temp = temp->next;
		total_nodes++;
	}
	return total_nodes;
}

int LinkedList::sumOfElements() const
{
	int sum = 0;
	Node* temp = head;
	while (temp) {
		sum += temp->id;
		temp = temp->next;
	}
	return sum;
}

void LinkedList::insert(int& index)
{
	if (index > 0 && index <= countNodes()) {
		Node* holder = new Node;
		char* name = new char[50]; //To be fixed by findLength()
		std::cout << "Enter the id = ";
		std::cin >> holder->id;
		std::cin.ignore();
		std::cout << "Enter the name = ";
		std::cin.getline(name, 50);
		holder->name = new char[findLength(name)];
		strcpy_s(holder->name, findLength(name), name);
		delete[] name;
		Node* temp = head;
		int itr = 1;
		while (itr != index) {
			temp->next;
			itr++;
		}
		holder->next = temp->next;
		temp->next = holder;
		holder = temp = nullptr;
	}
	else {
		std::cerr << "The index you entered is not valid!!!\n";
	}
}

void LinkedList::deleteNode(int& index)
{
	if (head) {
		if (index > 0 && index <= this->countNodes()) {
			Node* temp = head;
			if (index == 1) {
				head = head->next;
				delete[] temp->name;
				temp->name = nullptr;
				delete temp;
			}
			else {
				Node* prev_temp = head;
				temp = head->next;
				int itr = 2;
				while (itr != index) {
					prev_temp = temp;
					temp = temp->next;
					itr++;
				}
				prev_temp->next = temp->next;
				delete[] temp->name;
				temp->name = nullptr;
				delete temp;
				temp = nullptr;
				prev_temp = nullptr;
			}
		}
		else {
			std::cerr << "The entered index does not exist!!!\n";
		}
	}
	else {
		std::cerr << "There is nothing to delete!!!\n";
	}
}

void LinkedList::reverse()
{
	Node* temp = head,* q = nullptr, * r = nullptr;

	while (temp)
	{
		r = q;
		q = temp;
		temp = temp->next;
		q->next = r;
	}
	head = q;
	q = r = nullptr;

}

bool LinkedList::check_sort()
{
	int x = -65536;
	Node* temp = head;
	while (temp != NULL)
	{
		if (temp->id < x)
			return false;
		x = temp->id;
		temp = temp->next;
	}
	return true;
}

void LinkedList::pop()
{
	if (head) {
		if (!(head->next)) {
			delete[] head->name;
			head->name = nullptr;
			delete head;
			head = nullptr;
		}
		else {
			Node* temp = head;
			while (temp->next->next) {
				temp = temp->next;
			}
			delete[] temp->next->name;
			temp->next->name = nullptr;
			delete temp->next;
			temp->next = nullptr;
		}
	}
	else {
		std::cerr << "There is nothing to pop!!!\n";
	}
}

char* LinkedList::linear_search(int& id)
{
	if (head->id == id) {
		return head->name;
	}
	else {
		Node* temp = head->next;
		Node* prev_temp = head;
		while (temp) {
			if (temp->id == id) {
				prev_temp->next = temp->next;
				temp->next = head;
				head = temp;
				return head->name;
			}
			prev_temp = temp;
			temp = temp->next;
		}
		return nullptr;
	}
}

int LinkedList::linear_search(const char* name)
{
	if (head->name == name) {
		return head->id;
	}
	else {
		Node* temp = head->next;
		Node* prev_temp = head;
		while (temp) {
			if (temp->name == name) {
				prev_temp->next = temp->next;
				temp->next = head;
				head = temp;
				return head->id;
			}
			prev_temp = temp;
			temp = temp->next;
		}
		return -1;
	}
}

LinkedList::~LinkedList()
{
	if (head) {
		Node* temp = head;
		while (head) {
			head = head->next;
			delete[] temp->name;
			temp->name = nullptr;
			delete temp;
			temp = head;
		}
	}
}
