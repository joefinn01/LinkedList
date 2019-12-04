#include "LinkedList.h"
#include "SceneObject.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(SceneObject* data)
{
	head = new ListNode(data);
}

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::Append(SceneObject* data)
{
	ListNode* p = nullptr;

	p = head;

	while (p->next != nullptr)
	{
		p = p->next;
	}

	p->next = new ListNode(data);
}

void LinkedList::Delete()
{
	ListNode* p = nullptr;
	ListNode* temp = nullptr;

	p = head;


	while (p->next != nullptr)
	{
		temp = p->next;
		
		delete p;

		p = temp;
	}
}

void LinkedList::Insert(SceneObject* _data)
{
	ListNode* temp = head;

	head = new ListNode(_data, temp);
}

void LinkedList::InsertAt(int index, SceneObject* data)
{
	ListNode* p = head;
	ListNode* temp = nullptr;
	int count = index;

	for (int i = 0; i < count; i++)
	{


		if (p->next == nullptr)
		{
			cout << "Out of range!" << endl;
			break;
		}
		else
		{
			p = p->next;
		}
	}

	if (p->next != nullptr)
	{
		temp = p->next;
		p->next = new ListNode(data, temp);
	}
}

ListNode* LinkedList::Node(int index)
{
	ListNode* p = head;

	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}

	return p;
}

ListNode* LinkedList::Search(SceneObject* data)
{
	ListNode* p = head;

	while (p->data != data)
	{
		if (p->next == nullptr)
		{
			cout << "Data not found!" << endl;
			return nullptr;
		}
		else
		{
			p = p->next;
		}
	}

	return p;
}

void LinkedList::Print()
{
	ListNode* p = head;

	while (p->next != nullptr)
	{
		cout << p->data << endl;
		p = p->next;
	}

	cout << p->data << endl;
}

void LinkedList::DeleteNode(int index)
{
	ListNode* p = head;

	for (int i = 0; i < index - 1; i++)
	{
		p = p->next;
	}

	ListNode* temp = p->next;

	if (temp->next == nullptr)
	{
		delete temp;

		p->next = nullptr;
	}
	else
	{
		p->next = temp->next;

		delete temp;
	}
}

void LinkedList::DeleteFirst()
{
	ListNode* temp = head;

	head = temp->next;

	delete temp;
}
