//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT stack: Array-based implementation.
 Listing 7-1
 @file ArrayStack.h */

//Ramiz Faragalla

#ifndef ARRAY_STACK_
#include<string>
using namespace std;
#define ARRAY_STACK_

#include "StackInterface.h"

//lanes hold up to 10 cars
const int MAX_STACK = 10;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:	
	ItemType items[MAX_STACK];			// Array of stack items
	int      top;						// Index to top of stack
	
public:
	 ArrayStack();						// Default constructor
	 bool isEmpty() const;
	 bool push(const ItemType& newEntry);
	 bool pop();
	 ItemType peek() const;	
	 bool search(const ItemType &);		//searchs the stack for an ItemType

}; // end ArrayStack

template<class ItemType>
bool ArrayStack<ItemType>::search(const ItemType & other)
{
	//loop through array
	for (int i = 0; i <= top; i++)
	{	
		//exit once item is found
		if (items[i] == other)
			return true;
	}

	//if not found
	return false;
}

#include "ArrayStack.cpp"
#endif
