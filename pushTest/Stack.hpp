/*
	stack.hpp, class include file for the stack that holds Digrams

	made by Luke Gegick
*/

#ifndef STACK_H
#define STACK_H

#include <string>

using std::string;

//this stack holds digrams (ex. AE_)
class Stack
{
	private:
		char* stackPtr;
		int size;
		int top; //top element index in the stack
	public:
		Stack(int size);
		~Stack();
		string pop();
		void push(const string& digram);
		int getSize() const;
		int getTop() const;
		string topDigram() const;
		bool isFull() const;
		bool isEmpty() const;
		string oddHandling(const string& digram, int& size);
		friend std::ostream& operator<< (std::ostream& out, const Stack& myStack);
};

#endif