#include "MyStack.h"

#include <iostream>
#include <string>
using namespace std;

// Implementare stiva

void MyStack::push(int value) {
	MyStack* ptr = new MyStack;
	ptr->data = value;
	ptr->next = top;
	top = ptr;
}

char MyStack::pop() {

	if (isEmpty())
		cout << "Stiva goala" << endl;
	else {
		char temp = top->data;
		MyStack* ptr = top;
		top = top->next;
		delete(ptr);
		return temp;
	}

}

char MyStack::returnTop()
{
	if (top != NULL)
		return top->data;
	else 
		return '#';
}

bool MyStack::isEmpty() {
	if (top == NULL)
		return true;
	else
		return false;
}

// Functii ce nu tin de implementarea stivei

static int precedence(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}
bool isOperator(char ch) {
	if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
		return true;
	return false;
}
bool isOperand(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		return true;
	return false;
}
string reversePolish(string infixNotation) {
	MyStack stack;
	string postfixNotation = "";
	for (int i = 0; i < infixNotation.length(); i++) {
		if (isOperator(infixNotation[i])) {
			while (stack.returnTop() != '#' && stack.returnTop() != '(' && (precedence(infixNotation[i]) <= precedence(stack.returnTop())))
				postfixNotation += stack.pop();
			stack.push(infixNotation[i]);
		}
		else if (isOperand(infixNotation[i])) {
			postfixNotation += infixNotation[i];
		}
		else if (infixNotation[i] == '(') {
			stack.push(infixNotation[i]);
		}
		else if (infixNotation[i] == ')') {
			while (stack.returnTop() != '#' && stack.returnTop() != '(') {
				postfixNotation += stack.pop();
			}
			stack.pop();
		}
	}
	while (stack.returnTop() != '#') {
		postfixNotation += stack.pop();
	}
	return postfixNotation;
}

string polish(string notation) {
	string reverseNotation = "";
	string prefix = "";
	for (int i = notation.length(); i >= 0; i--) {
		char token = notation[i];
		if (token == '(')
			notation[i] = ')';
		if (token == ')')
			notation[i] = '(';
		reverseNotation += notation[i];
	}
	string postfix = reversePolish(reverseNotation);
	for (int i = postfix.length(); i >= 0; i--) {
		prefix += postfix[i];
	}
	return prefix;
}


int evaluate(string postfixNotation) {
	MyStack stack;
	int num1 = 0;
	int num2 = 0;
	int answer = 0;
	for (int i = 0; i < postfixNotation.length(); i++) {

		if (isOperand(postfixNotation[i]))
			stack.push(postfixNotation[i]);
		else if (isOperator(postfixNotation[i])) {
			num1 = static_cast<int>(stack.pop()) - 48;
			num2 = static_cast<int>(stack.pop()) - 48;
			if (postfixNotation[i] == '^') {
				answer = num2 ^ num1;
				stack.push(answer + 48);
			}
			else if (postfixNotation[i] == '/') {
				answer = num2 / num1;
				stack.push(answer + 48);
			}
			else if (postfixNotation[i] == '*') {
				answer = num2 * num1;
				stack.push(answer + 48);
			}
			else if (postfixNotation[i] == '-') {
				answer = num2 - num1;
				stack.push(answer + 48);
			}
			else if (postfixNotation[i] == '+') {
				answer = num2 + num1;
				stack.push(answer + 48);
			}
		}

	}
	return answer;
}