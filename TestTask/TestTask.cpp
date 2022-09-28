#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <iostream>
#include <string>
#include "PriorityStack.h"

int main()
{
    //Creating stack with int type

    PriorityStack<int> myStack;
    
    //Pushing values

    myStack.Push(5, 42);
    myStack.Push(1, 5);
    myStack.Push(2, 3);
    myStack.Push(3, 7);
    myStack.Push(1, 4);
    myStack.Push(2, 6);
    myStack.Push(1, 8);
    myStack.Push(2, 10);

    
    //OUTPUT: 42 7 10 6 3 8 4 5 

    while(!myStack.IsEmpty())
        std::cout << myStack.Pop() << std::endl;

    //Trying to Pop value from empty stack, OUTPUT: Stack is empty

    myStack.Pop();

    
    //Creating stack with string type
    PriorityStack<std::string> secondStack;

    secondStack.Push(5, "five");
    secondStack.Push(3, "three");

    secondStack.Clear();

    secondStack.Push(2, "three");
    secondStack.Push(2, "two");
    secondStack.Push(1, "five");
    secondStack.Push(3, "one");
    secondStack.Push(5, "I'am poped!");
    secondStack.Pop();
    secondStack.Push(1, "four");

    //OUTPUT: one two three four five
    while (!secondStack.IsEmpty())
        std::cout << secondStack.Pop() << std::endl;

    myStack.Pop();

    secondStack.Clear();
    secondStack.Clear();
    
    secondStack.Push(5, "one");

    secondStack.Push(3, "two");
    secondStack.Push(2, "four");
    secondStack.Push(2, "three");
    secondStack.Push(1, "five");

    //OUTPUT: one two three four five
    while (!secondStack.IsEmpty())
        std::cout << secondStack.Pop() << std::endl;


    _CrtDumpMemoryLeaks();
}


