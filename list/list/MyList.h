#pragma once

#include "ListObject.h"

template <class T>
class MyList
{
public:
	MyList(T value)
	{
		head = new Object<T>();
		head->value = value;
	}

	void pushBack(T value)
	{
		elementNumber++;

		if (head == nullptr)
		{
			head = new Object<T>();
			head->value = value;
			head->next = nullptr;

			return;
		}
		
		Object<T>* temp = head;

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = new Object<T>();
		temp->next->value = value;
		temp->next->next = nullptr;
	}

	void pushFront(T value)
	{
		Object<T>* temp = head;

		head = new Object<T>();
		head->value = value;

		head->next = temp;
		elementNumber++;
	}

	void popFront()
	{
		if (head == nullptr) return;

		Object<T>* temp = head;

		head = head->next;

		delete temp;
		elementNumber--;
	}

	void popBack()
	{
		if (head == nullptr) return;

		elementNumber--;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}


		Object<T>* temp = head;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = nullptr;
		
	}

	void insert(int index, T value)
	{
		if (index > elementNumber) return;

		size_t element = 0;

		Object<T>* temp = head;
		while (element != index-1)
		{
			element ++;
			temp = temp->next;
		}

		Object<T>* newObject = new Object<T>();
		newObject->value = value;
		newObject->next = temp->next;
		temp->next = newObject;
	}

	void remove(int index)
	{
		if (index > elementNumber) return;

		size_t element = 0;

		Object<T>* temp = head;
		while (element - 1 != index - 2)
		{
			element++;
			temp = temp->next;
		}

		Object<T>* tempObject = temp->next->next;
		delete temp->next;
		temp->next = tempObject;
	}

	void printList()
	{
		Object<T>* temp = head;

		while (temp != nullptr)
		{
			std::cout << temp->value << std::endl;
			temp = temp->next;
		}
	}

private:
	Object<T>* head;
	size_t elementNumber = 1;
};