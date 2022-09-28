#pragma once

#include <iostream>

constexpr int startStackSize = 4;

template <class T>
class PriorityStack
{
public:
	PriorityStack()
	{
		InitStack();
	}

	void Push(int priority, T value)
	{
		if (maxStackSize == 0)
			InitStack();

		if (currentStackSize == maxStackSize)
			ExpandStack();

		
		currentStackSize += 1;
		stack[currentStackSize-1] = StackItem(priority, value);

		for (int i = currentStackSize-1; i != 0; i--)
			if (stack[i].priority < stack[i - 1].priority)
			{
				std::swap(stack[i - 1], stack[i]);
			}
		
	}
	T Pop()
	{
		if (IsEmpty())
		{
			std::cout << "Stack is empty, returning NULL" << std::endl;
			return NULL;
		}

		T item = stack[currentStackSize-1].value;
		currentStackSize -= 1;

		if (currentStackSize == 0)
			Clear();

		return item;
	}
	bool IsEmpty()
	{
		return (currentStackSize == 0);
	}
	void Clear()
	{
		if (maxStackSize != 0)
		{
			maxStackSize = 0;
			currentStackSize = 0;
			delete[] stack;
		}
	}
	~PriorityStack()
	{
		Clear();
		
	}

	

private:

	class StackItem
	{
	public:
		int priority;
		T value;
		StackItem(int p,T v)
		{
			priority = p;
			value = v;
		}
		StackItem()
		{

		}

		~StackItem()
		{

		}
	};

	StackItem* stack = nullptr;
	int currentStackSize = 0;
	int maxStackSize = startStackSize;

	void ExpandStack()
	{
		StackItem* newStack = new StackItem[maxStackSize * 2];

		for (int i = 0; i < maxStackSize; i++)
			newStack[i] = stack[i];

		delete[] stack;

		stack = newStack;
		maxStackSize *= 2;
	}

	void InitStack()
	{
		maxStackSize = startStackSize;
		currentStackSize = 0;
		stack = new StackItem[startStackSize];
	}
};
