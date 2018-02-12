#include <string>

using namespace std;

#ifndef LINKEDLIST
#define LINKEDLIST

class LinkedList
{
private:
	struct Node *head;
	struct Node *tail;

public:
	bool insert(string name, string data);
	bool remove(string name);
	bool find(string name);
	bool dump();
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
};


#endif