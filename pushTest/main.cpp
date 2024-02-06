/*
	Main file for the Digram stack

	made by Luke Gegick
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "Stack.hpp"

using std::setw;
using std::setfill;
using std::left;
using std::cout;

bool stringAlphaCheck(const string& userStr);

int main()
{
	string userStr;
	Stack userStack(20);

	while (userStr != "quit" && userStr != "Quit")
	{
		cout << "\033[2J\033[1;1H"; //clear screen code

		cout << "Stack Program Test, You have the following commands:\n"
			<< setw(15) << setfill(' ') << "'push': " << "\tadds item unto the stack\n"
			<< setw(15) << setfill(' ') << "'pop': "  << "\tremoves an item from the stack and displays it\n"
			<< setw(15) << setfill(' ') << "'size': " << "\tdisplays the size of the stack\n"
			<< setw(15) << setfill(' ') << "'top': "  << "\tdisplays the top index and the last value entered\n"
			<< setw(15) << setfill(' ') << "'full': " << "\tshows either true/false depending on if room is left in the stack\n"
			<< setw(15) << setfill(' ') << "'empty': "<< "\tshows either true/false depending on if values are entered into stack\n"
			<< setw(15) << setfill(' ') << "'stack': "<< "\tdisplays the stack\n\n";

		cout << "Your input: ";
		std::cin >> userStr;
		if (userStr == "push" || userStr == "Push")
		{
			string pushAgain("Y");
			while (pushAgain == "Y" || pushAgain == "y")
			{
				string pushStr;
				cout << "\033[2J\033[1;1H"; //clear screen code

				//validate character inputs
				bool flag1 = true;
				do
				{
					cout << "What digram would you like to push?: ";
					std::cin.clear(); //clear input stream
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					//ignore the inputs sitting in the buffer
					std::getline(std::cin, pushStr);
					if (stringAlphaCheck(pushStr) == true)
					{
						userStack.push(pushStr);
						flag1 = false;
					}
					else if (stringAlphaCheck(pushStr) == false)
					{
						cout << "\033[2J\033[1;1H";
						cout << "Only enter alphabetic characters into the stack\n\n";
					}
				} while (flag1);

				//display the results
				cout << "Stack with the data added in\n";
				cout << userStack;

				cout << "Would you like to push again (Y/N): ";
				std::cin >> pushAgain;

				cout << "\033[2J\033[1;1H"; //clear screen code
			}
		}
		else if (userStr == "pop" || userStr == "Pop")
		{
			string popAgain("Y");
			while (popAgain == "Y" || popAgain == "y")
			{
				cout << "\033[2J\033[1;1H"; //clear screen code
				string popStr = userStack.pop();

				cout << "Here is the popped value: " << popStr << "\n\n";
				cout << userStack;

				cout << "Would you like to pop another value (Y/N)?: ";
				std::cin >> popAgain;
				cout << "\033[2J\033[1;1H"; //clear screen code
			}
		}
		else if (userStr == "size" || userStr == "Size")
		{
			cout << "\033[2J\033[1;1H"; //clear screen code
			cout << "The size of the stack is: " << userStack.getSize() << "\n\n";

			cout << "Enter any key to continue: ";
			std::cin >> userStr;
			cout << "\033[2J\033[1;1H"; //clear screen code
		}
		else if (userStr == "top" || userStr == "Top")
		{
			cout << "\033[2J\033[1;1H"; //clear screen code
			cout << "The top index is: " << userStack.getTop() << '\n';
			cout << "The last digram entered is: " << userStack.topDigram() << "\n\n";

			cout << "Enter any key to continue: ";
			std::cin >> userStr;
			cout << "\033[2J\033[1;1H"; //clear screen code
		}
		else if (userStr == "full" || userStr == "Full")
		{
			cout << "\033[2J\033[1;1H"; //clear screen code
			bool userFull = userStack.isFull();
			if (userFull == true)
			{
				cout << "The Stack is full\n\n";
			}
			else
			{
				cout << "There is still room in the Stack\n\n";
			}
			cout << "Enter any value to continue: ";
			std::cin >> userStr;
			cout << "\033[2J\033[1;1H"; //clear screen code
		}
		else if (userStr == "empty" || userStr == "Empty")
		{
			cout << "\033[2J\033[1;1H"; //clear screen code
			bool Empty = userStack.isEmpty();
			if (Empty == true)
				cout << "The Stack is empty\n\n";
			else
				cout << "The Stack is not empty\n\n";

			cout << "Enter any key to continue: ";
			std::cin >> userStr;
		}
		else if (userStr == "stack" || userStr == "Stack")
		{
			cout << "\033[2J\033[1;1H"; //clear screen code
			cout << userStack;

			cout << "\n\nEnter any key to continue: ";
			std::cin >> userStr;
			cout << "\033[2J\033[1;1H"; //clear screen code
		}

		//once user finishes an above function, or enters function incorrectly
		cout << "Enter 'quit' to exit program, and 'enter' to continue: ";
	} 

	return 0;
}

//returns false if string contains non-alphbetic characters
//returns true otherwise
bool stringAlphaCheck(const string& userStr)
{
	int  strSize = userStr.size();
	for (int i = 0; i < strSize; i++)
	{
		if (isalpha(userStr[i]) == false && ispunct(userStr[i]) == 0 && userStr[i] != ' ')
		{
			return false;
		}
	}
	return true;
}