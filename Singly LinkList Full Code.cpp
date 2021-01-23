#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *next;
	node(int val)
	{
		data = val;
		next = NULL;
	}
};
class linklist
{
public:
	node *head;
	node *tail;
	linklist()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int val)
	{
		node *mynode = new node(val);
		if (head == NULL)
		{
			head = mynode;
			tail = mynode;
		}
		else
			mynode->next = head;
		head = mynode;
	}
	void inserttail(int val)
	{

		node *mynode = new node(val);
		node *temp = head;
		if (head == NULL)
		{
			head = mynode;
			tail = mynode;
		}
		else
		{
			tail->next = mynode;
			tail = mynode;
		}
			
		
			
	}
	bool search(int key)
	{
		node *temp = head;
		
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				cout << "Key Found" << endl;
				return true;
				
			}
				
			temp = temp->next;
				
		}
		cout << "Key Not Found" << endl;
		return false;
		
	}
	void update(int key,int rep)
	{
		node *temp = head;
		if (head == NULL)
		{
			cout << "LIST is Empty" << endl;
		}
		while (temp != NULL)
		{
			if (temp->data == key)
			{
				temp->data = rep;
				break;
			}
			temp = temp->next;
		}
		
	}
	void insertafter(int key, int val)
	{
		node *temp = head;
		node *mynode = new node(val);
		if (temp->data == key)
		{
			mynode->next = temp->next;
			temp->next = mynode;
		}
		else
			cout << "Key not Found" << endl;
	}
	void deletehead()
	{
		node *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	void display()
	{
		node *temp = head;
		if (head == NULL)
		{
			cout << "Linklist is Empty" << endl;
		}
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};

int main()
{
	linklist obj;
	int ch, val;
	int num;
	cout << "1) Insert at Head" << endl;
	cout << "2) Insert at Tail" << endl;
	cout << "3) Insert After" << endl;
	cout << "4) Search in LinkList" << endl;
	cout << "5) Update in LinkList " << endl;
	cout << "6) Delete HEAD " << endl;
	cout << "7) Display LinkList" << endl;
    cout << "8) Exit" << endl;
	do {
		cout << "Enter choice: " << endl;
		cin >> ch;
		switch (ch) {
		case 1: {
					cout << "Enter value to be Insert at Head:" << endl;
					cin >> val;
					obj.insert(val);
					break;
		}
		case 2: {
					cout << "Enter value to be Insert at Tail:" << endl;
					cin >> num;
					obj.inserttail(num);
					break;
		}
		case 3: {
					cout << "Enter after ehich u want insert:" << endl;
					int num5;
					cin >> num5;
					cout << "Enter value after u want insert:" << endl;
					int num6;
					cin >> num6;
					obj.insertafter(num5,num6);
					break;
		}
		case 4: {
					cout << "Enter Number to Search:" << endl;
					int num2;
					cin >> num2;
					obj.search(num2);
					break;
		}
		case 5: {
					cout << "Enter Number Which you Want to Update:" << endl;
					int num3;
					cin >> num3;
					cout << "Enter Number with  Which you Want to Update:" << endl;
					int num4;
					cin >> num4;
					obj.update(num3,num4);
					break;
		}
		case 6: {
					obj.deletehead();
					break;
		}
		case 7: {
					obj.display();
					break;
		}
		case 8: {
					cout << "Exit" << endl;
					break;
		}
		default: {
					 cout << "Invalid Choice" << endl;
		}
		}
	} while (ch != 8);
	return 0;
}

