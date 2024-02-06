/*
	stack.cpp, the stack.hpp implementation file 

	made by Luke Gegick
*/

#include "Stack.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

using std::left;
using std::setw;
using std::setfill;

Stack::Stack(int size)
{
	stackPtr = new char[size];
	this->size = size;
	top = -1;
}

Stack::~Stack()
{
	delete[] stackPtr;
}
string Stack::pop()
{
	if (isEmpty())
	{
		std::cerr << "Err: Stack is empty" << std::endl;
		std::exit(1);
	}
	else
	{
		//since top indexs a space (refer to top - 1 and top - 2 for characters
		string temp;
		if (top - 2 >= 0)
		{
			temp += stackPtr[top - 2];
			temp += stackPtr[top - 1];
			temp += ' ';
			top = top - 3; //reset to the new top
			return(temp);
		}
		else
		{
			return("");
		}
	}
}

void Stack::push(const string& digram)
{
	if (isFull())
	{
		std::cerr << "Err: stack is full" << std::endl;
	}
	else
	{
		string pushStr = digram;
		int strSize = digram.size();
		top++; 
		int increment(0);

		//handle the odd push case, convert to even (add a space char)
		if (strSize % 2 != 0)
		{
			pushStr = oddHandling(digram, strSize);
		}

		while (increment < strSize)
		{
			//check no overflow occurs
			if (top >= (size - 1))
			{
				std::cerr << "Err: stack overflow\n";
				std::exit(1);
			}

			//check if the pushStr[increment] is a piece of punctuation
			if (ispunct(pushStr[increment]))
			{
				stackPtr[top] = ' ';
			}
			else
			{
				//add next letter to the stack
				stackPtr[top] = std::toupper(pushStr[increment]);
			}

			//check the top doesnt go above
			if (top == size - 1)
			{
				std::cerr << "Err: Exceeded the stack limits";
				exit(1);
			}
			top++;

			//FIX ISSUE WHERE A SPACE IS ADDED EVERY TIME MULTIPLE CHARS ENTERED EX. AC DE
			//continue the while loop
			increment++;
		}

		//add a space to the end of the stack
		stackPtr[top] = ' ';

	}
}

//converts an odd digram to an even one (user enters Hello)
//to ensure no data is lost convert for ex hello to helllo
//Precondition: pass a string, as well as its size
string Stack::oddHandling(const string& digram, int& size)
{
	//if user pushes an empty string
	if (size == 0)
	{
		std::cerr << "Empty string presented to stack: Fatal Error\n";
		std::exit(1);
	}
	else if(size == 1) //if string is only one char long
	{
		string newStr = digram; //add a space to the char
		newStr += ' ';
		size = 2;
		return newStr;
	}
	else
	{
		string newStr = digram;
		newStr += ' ';
		size = newStr.size();
		return newStr;
	}

	/*
	//make a new copy of the string
	string temp = digram.substr(0, size - 1);

	//append the elememts (ex Hello becomes Helllo) 
	char lastElement = digram[size - 1];
	temp += digram[size - 2];
	temp += lastElement;

	//recalculate the size of the string
	size = temp.size();

	return temp; */
}

bool Stack::isFull() const
{
	if (top == (size - 1))
	{
		return true;
	}
	else
		return false;
}

bool Stack::isEmpty() const
{
	if (top == -1)
	{
		return true;
	}
	else
		return false;
}

int Stack::getSize() const
{
	return size;
}

int Stack::getTop() const
{
	return top;
}

string Stack::topDigram() const
{
	if (top - 2 > 0)
	{
		string rtnString;
		rtnString += stackPtr[top - 2];
		rtnString += stackPtr[top - 1];
		rtnString += stackPtr[top];
		return rtnString;
	}
	else
	{
		std::cerr << "No Digram to be returned\n";
		return " ";
		exit(1);
	}
}

std::ostream& operator<< (std::ostream& out, const Stack& myStack)
{
	//display helper checks if the second value is a space (A_)
	//and shows as an underscore to improve readability
	char DisplayHelper;

	if (!myStack.isEmpty())
	{
		//table header print out
		out << "Contents of the Stack include: \n";
		out << "Stack Index" << setw(5) << setfill(' ') 
			<< "|" << setw(15) << setfill(' ') << "Index Value" << '\n';
	 
		//output the table of the data
		int DisplayHelperInc(1);
		for (int i = 0; i <= myStack.top; i++)
		{
			DisplayHelper = myStack.stackPtr[i];
			if ( ((i == 1) || (i - (3 * DisplayHelperInc)) == 1) && DisplayHelper == ' ')
			{
				DisplayHelper = '_';
				DisplayHelperInc++;
			}
			out << setw(7) << i << setw(9) << setfill(' ') <<
				"|" << setw(10) << setfill(' ') << DisplayHelper << '\n';

		} 
		return out;
	} 
	else
	{
		//table header print out
		out << "Contents of the Stack include: \n";
		out << "Stack Index" << setw(5) << setfill(' ')
			<< "|" << setw(15) << setfill(' ') << "Index Value" << "\n\n\n";
	}
}

