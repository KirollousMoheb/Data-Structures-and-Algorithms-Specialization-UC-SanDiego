#include <iostream>
#include <stack>
#include <string>
using namespace std;



bool check(char opening,char closing) {  // function to check matching pairs in if conditions
	//it returns true to assure the if condition
	//or return false if no if conditions from the below is met
	if (opening=='{' && closing=='}')
	{
		return true;
	}
	if (opening == '(' && closing == ')')
	{
		return true;

	}
	if (opening == '[' && closing == ']')
	{
		return true;

	}
	return false;
}

int main() {
	int answer=0;//initializing and declaring an answer value to specify the position of the unmatching bracket
	char x;
	string input;
	getline(cin, input);//getting input from the user
	stack <char> list;//creating a stack to add opening brackets to it or remove from it if paired 
	for (int i = 0; i < input.length(); i++)//for loop go through the inputs chars
	{
		if (input[i] == '(' || input[i] == '{' || input[i] == '[')//if any opening bracket is met in the input
		{
			list.push(input[i]);// push it to the list stack 

		}
		if (input[i] == ')' || input[i] == '}' || input[i] == ']') {//if any closing bracket is met in the input


			if (list.empty() || !check(list.top(), input[i]))//two conditions
				//if it doesn't pair with the top element in the stack
				//Or
				//if the stack is empty which means that there is no opening tagss at all

			{
				answer = i + 1;//get the unmatched element index and add 1 to it
				break;
			}
			else//else if they are matched 
			{
				list.pop();//pop the top opening bracket in the stack
			}
		}
	}

	if (answer!=0) { //if the answer is not zero print it
		cout << answer ;
	}
	else if(list.size()){//if the list is not empty after going out from the for loop
		x = list.top();//get the top opening bracket that wasn't paired
		//I was supposed to print it's position but i couldn't so I printed it instead
		cout << x;
	}
	else//else if  the list is empty then all brackets are paired
	{
		cout << "Success";
	}
}