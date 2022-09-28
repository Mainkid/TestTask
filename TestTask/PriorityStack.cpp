//
//
//
//template <class T>
//PriorityStack<T>::PriorityStack()
//{
//	maxStackSize = startStackSize;
//	currentStackSize = 0;
//}
//
//template <class T>
//PriorityStack<T>::PriorityStack(int startSize)
//{
//	maxStackSize = startSize;
//	currentStackSize = 0;
//}
//
//
//template <class T>
//void PriorityStack<T>::Push(int priority, T value)
//{
//	if (currentStackSize == maxStackSize)
//		ExpandStack();
//	currentStackSize += 1;
//
//	stack[currentStackSize] = new StackItem(priority, value);
//
//	for (int i=currentStackSize;i!=0;i--)
//		if (stack[i].priority < stack[i - 1].priority)
//		{
//			std::swap(stack[i - 1], stack[i]);
//		}
//
//	
//}
//
//
//template <class T>
//T PriorityStack<T>::Pop()
//{
//
//	T item = stack[currentStackSize];
//	currentStackSize -= 1;
//	return item;
//}
//
//template <class T>
//bool PriorityStack<T>::IsEmpty()
//{
//	return (currentStackSize == 0);
//}
//
//template <class T>
//void PriorityStack<T>::Clear()
//{
//	delete[] stack;
//}
//
//template <class T>
//void PriorityStack<T>::ExpandStack()
//{
//	StackItem* newStack = new StackItem[maxStackSize * 2];
//
//	for (int i = 0; i < maxStackSize; i++)
//		newStack[i] = stack[i];
//
//	Clear();
//
//	stack = newStack;
//	maxStackSize += 1;
//}