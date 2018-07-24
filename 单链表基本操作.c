#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node* create(void)
{

	node *p1, *p2, *head;
	int a;
	head = 0;
	p2 = 0;
	cout << "pls input data, and end with -1\n";
	cin >> a;
	while (-1 != a)
	{
		p1 = new node;
		p1->data = a;
		if (0 == head)
		{
			head = p1;
			p2 = p1;
		}
		else {
			p2->next = p1;
			p2 = p1;
		}
		cin >> a;
	}
	if (head)
		p2->next = 0;

	return head;
}

void print(const node *head)
{
	const node *p;
	p = head;

	cout << "all data in list: \n";
	while (0 != p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}

node* delete_one_node(node *head, int num)
{
	node *p1, *p2;
	if (0 == head)
	{
		cout << "list is null" << endl;
		return 0;
	}
	if (head->data == num)
	{
		p1 = head;
		head = head->next;
		delete p1;
	}
	else {
		p1 = head;
		p2 = head->next;
		while (p2 && p2->data != num && p2->next != 0)
		{
			p1 = p2;
			p2 = p2->next;
		}
		if (p2 && p2->data == num)
		{
			p1->next = p2->next;
			delete p2;
		}
		else {
			cout << "can not find the one node\n";
		}
	}
	return head;
}

node* insert(node *head, node *p)
{
	node *p1, *p2;
	if (0 == head)
	{
		head = p;
		p->next = 0;
		return head;
	}
	if (head->data >= p->data)
	{
		p->next = head;
		head = p;
		return head;
	}

	p2 = p1 = head;
	while (p2->next && p2->data < p->data)
	{
		p1 = p2;
		p2 = p2->next;
	}
	if (p2->data < p->data) {
		p2->next = p;
		p->next = 0;
	}
	else {
		p->next = p2;
		p1->next = p;
	}
	return head;
}

node* create_sort(void)
{
	node *p1, *head = 0;
	int a;
	cout << "pls input data, and end with -1\n";
	cin >> a;
	while (-1 != a)
	{
		p1 = new node;
		p1->data = a;
		head = insert(head, p1);
		cin >> a;
	}
	return head;
}

void delete_chain(node *h)
{
	node *p;
	while (h)
	{
		p = h;
		h = h->next;
		delete p;
	}
}

int main()
{
	node *head;
	int num;
	head = create();     // create list without sort;
	print(head);
	cout << "input the data which node you wanna delete\n";
	cin >> num;
	head = delete_one_node(head, num);   // delete the specified node;
	print(head);
	delete_chain(head);
	head = create_sort();   // create list with sort;
	print(head);
	delete_chain(head);     // delete the list chain;

	return 0;
}