#pragma once

#include <iostream>
#include <string>

using namespace std;
class MyStack {

private:
	char data;
	MyStack* next;
	MyStack* top;

public:
	MyStack() : data(0), next(NULL), top(NULL) {}
	bool isEmpty();
	void push(int a);
	char pop();
	char returnTop();
};


// evaluate functions

static int precedence(char ch);
bool isOperator(char ch);
bool isOperand(char ch);
string polish(string notation);
string reversePolish(string infixNotation); 
int evaluate(string postfixNotation);

