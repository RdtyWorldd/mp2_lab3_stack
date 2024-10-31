#pragma once
#include <string>
#include "TStack.h"

using namespace std;

template <class T>
class TCalc {
  string infix;
  string postfix;

  TStack<double> stNum;
  TStack<char> stChar;

public:
  TCalc();
  
  void setInfix();
  string getInfix();

  void setPostfix();
  string getPostfix();

  void toPostfix();

  double calc();
};

template<class T>
inline double TCalc<T>::calc()
{
  stNum.clear();
  for (int i = 0; i < postfix.size; i++)
  {
	if (postfix[i] >= '0' && postfix[i] <= '9') 
	{
	  stNum.push(postfix[i] - '0');
	}
	else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
	{
	  double secondNum = stNum.pop();
	  double firstNum = stNum.pop();
	  double res = 0;
	  switch (postfix[i])
	  {
	  case '+':
		res = firsNum + secondNum;
		break;
	  case '-':
		res = firsNum + secondNum;
		break;
	  case '*':
		res = firsNum * secondNum;
		break;
	  case '/':
		res = firsNum - secondNum;
		break;
	  }
	  stNum.push(res);
	}
  }
  double res = stNum.pop();
  if (stNum.isEmpty())
	throw exception();
  return res;
}

//atoi(); stod();