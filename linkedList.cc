#include <iostream>
#include <string>

#include "linkedList.h"

using namespace std;

struct Node {
    string name;
    string data;
    struct Node *next;
};

/**
 * inserts a node into the list. If there is a duplicate, replaces all instances with new data
 * @param {string} name 
 * @param {string} data
 * @return {bool} success
 **/
bool LinkedList::insert(string name, string data)
{
	// create new node
	Node *n = new Node;
	n -> name = name;
	n -> data = data;
	n -> next = NULL;

	// check that list is not empty
	if (head == NULL)
	{
		// if it is, set head and tail to n
		head = n;
		tail = n;
		cout << "ADDED " << name << endl;
		return true;
	}

	// list is not empty, insert into list
	struct Node *temp = head;
	bool updated = false;
	for (; temp -> next != NULL; temp = temp -> next)
	{
		if (temp -> name == name)
		{
			temp -> data = data;
			cout << "UPDATED " << name << endl;
			updated = true; 
		}
	}
	// did not update, insert node at end of list
	if (updated == false)
	{
		temp -> next = n;
		tail = n;
		cout << "ADDED " << name << endl;
	}
	return true;
}

/**
 * removes all nodes with given name
 * @param {string} name 
 * @return {bool} success
 **/
bool LinkedList::remove(string name)
{
	struct Node *temp = head;
	struct Node *previous = NULL;
	bool deleted = false;
	for (;  temp != NULL; temp = temp -> next)
	{
		// we've found the node, let's replace
		if (temp -> name == name)
		{
			// reassign last node to skip curr
			if (previous != NULL) 
			{
				previous -> next = temp -> next;
			}
			// last node in list
			if (temp -> next == NULL)
			{
				tail = temp;

			} 
			if(head == temp)
			{ // first node in list
				head = temp -> next;
			}
			deleted = true;	
			cout << "REMOVED " << name << endl;
		}
		previous = temp;
	}
	if (deleted == false)
	{
		// could not find node
		cout << "COULD NOT FIND " << name << endl; 
		return false;
	}
}

/**
 * finds node with given name
 * @param {string} name 
 * @return {bool} success
 **/
bool LinkedList::find(string name)
{
	struct Node *temp = head;
	for (;  temp != NULL; temp = temp -> next)
	{
		// we've found the node!
		if (temp -> name == name)
		{
			cout << "FOUND " << name << "," << temp-> data << endl;
			return true;
		}
	}
	cout << "COULD NOT FIND " << name << endl;
	return false;
}

/**
 * prints out all data in list
 * @return {bool} success
 **/
bool LinkedList::dump()
{
	struct Node *temp = head;
	for (;  temp != NULL; temp = temp -> next)
	{
		cout << " -- " << temp -> name << ", " << temp-> data << endl;
	}
	return true;
}

int main()
{   
	LinkedList ll;
	ll.insert("David", "test data 1");
	ll.dump();
	ll.insert("Sam", "test data 2");
	ll.dump();
	ll.insert("David", "test data 3");
	ll.dump();


	ll.remove("David");
	ll.dump();

	ll.remove("Sam");

	ll.dump();

    return 0;
}