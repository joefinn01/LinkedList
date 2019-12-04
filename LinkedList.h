#pragma once

class SceneObject;

struct ListNode
{
	ListNode(SceneObject* _data)
	{
		data = _data;
		next = nullptr;
	}

	ListNode(SceneObject* _data, ListNode* _next)
	{
		data = _data;
		next = _next;
	}

	ListNode()
	{
		data = nullptr;
		next = nullptr;
	}

	SceneObject* data;
	ListNode* next;
};

class LinkedList
{
public:
	LinkedList(SceneObject* data);
	LinkedList();
	~LinkedList();
	
	void Append(SceneObject* data);
	void Delete();
	void DeleteNode(int index);
	void DeleteFirst();
	void Insert(SceneObject* _data);
	void InsertAt(int index, SceneObject* data);
	void Print();
	ListNode* Node(int index);
	ListNode* Search(SceneObject* value);


private:
	ListNode * head;
};
