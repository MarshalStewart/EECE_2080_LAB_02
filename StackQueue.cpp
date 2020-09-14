/*
	Lab Group 12
	Marshal Stewart stewa2m3
	Ilan Schindler schinim
	Steven LeVasseur levasssk

	StackQueues.cpp : Defines the exported functions for the DLL application.

*/

#include "StackQueue.h"


/* Array Based Stack */

ArrayBasedStack::ArrayBasedStack()
{
	for (int item : stack)
	{
		item = -1;
	}

	topIndex = -1;
}

ArrayBasedStack::~ArrayBasedStack() {}

bool ArrayBasedStack::isEmpty() const
{
	return topIndex == -1;
}

bool ArrayBasedStack::isFull() const
{
	return topIndex == MAX_STACK_LEN - 1;
}

bool ArrayBasedStack::push(int val)
{
	if (!isFull())
	{
		stack[++topIndex] = val;
		return true;
	}
	else
	{
		
		return false;
	}
}

bool ArrayBasedStack::pop()
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		stack[topIndex--] = -1;
		return true;
	}
}

int ArrayBasedStack::peek()
{
	if (isEmpty())
	{
		throw "ADT is empty";
	}
	else
	{
		//TODO
		return stack[topIndex];
	}
}

std::string ArrayBasedStack::toString()
{
	std::string str = "";

	for (int i = 0; i < MAX_STACK_LEN; i++)
	{
		if (stack[i] >= 0)
			str += std::to_string(stack[i]);

		if (i < 10 && stack[i] >= 0)
		{
			str += " ";
		}
	}

	return str.substr(0, str.length() - 1);
}

/* Array Based Queue */

ArrayBasedQueue::ArrayBasedQueue() : backIndex(0), frontIndex(0) {}

ArrayBasedQueue::~ArrayBasedQueue() {}

bool ArrayBasedQueue::isEmpty() const
{
		return false;
}

bool ArrayBasedQueue::isFull() const {

}

bool ArrayBasedQueue::enQueue(std::string val) {
	if(!isFull()) {
		queue[backIndex] = val;
		backIndex = (backIndex++) % MAX_QUEUE_LEN;
		return true;
	}
	else{
		return false;
	}

}

bool ArrayBasedQueue::deQueue() {
	if(!isEmpty()) {
		queue[frontIndex] = "";
		frontIndex = (frontIndex++) % MAX_QUEUE_LEN;
		return true;
	}
	else{
		return false;
	}

}

std::string ArrayBasedQueue::peekFront() {
	if (isEmpty())
	{
		throw "ADT is emtpy";
	}
	else
	{
		//TODO
	}
}
