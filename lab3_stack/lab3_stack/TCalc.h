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

  int priority(char action);
public:
  TCalc();
  
  void setInfix(string _infix);
  string getInfix();

  void setPostfix(string _postfix);
  string getPostfix();

  void toPostfix();

  double calc();
};

template<class T>
inline int TCalc<T>::priority(char action)
{
  int priority = 0;
  switch (action) 
  {
  case '(':
  case ')':
	break;
  case '-':
  case '+':
	priority = 1;
	break;
  case '*':
  case '/':
	priority = 2;
	break;
  case '^':
	priority = 3;
	break;
  default:
	throw exception("not operation");
	break;
  }
  return priority;
}

template<class T>
inline TCalc<T>::TCalc():stNum(), stChar()
{
  infix = "";
  postfix = "";
}

template<class T>
inline void TCalc<T>::setInfix(string _infix)
{
  infix = _infix;
  //временно
  stNum = TStack<double>(infix.size()/2);
  stChar = TStack<char>(infix.size()/2);
}

template<class T>
inline string TCalc<T>::getInfix()
{
  return infix;
}

template<class T>
inline void TCalc<T>::setPostfix(string _postfix)
{
  postfix = postfix;
}

template<class T>
inline string TCalc<T>::getPostfix()
{
  return postfix;
}

template<class T>
inline void TCalc<T>::toPostfix()
{
  string s = "(" + infix + ")";
  for (int i = 0; i < s.size(); i++)
  {
	if (s[i] == '(')
	  stChar.push(s[i]);
	else if (s[i] == ')')
	{
	  char a = stChar.pop();
	  while (a != '(')
	  {
		postfix += ' ';
		postfix += a;
		a = stChar.pop();
	  }
	  
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
	  postfix += s[i];
	  //postfix += ' ';
	}
	else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^')
	{
	  postfix += ' ';
	  while (priority(s[i]) <= priority(stChar.top()))
	  {
		postfix += stChar.pop();
		postfix += ' ';
	  }
	  stChar.push(s[i]);
	}
  }
}

template<class T>
inline double TCalc<T>::calc()
{
  stNum.clear();
  for (int i = 0; i < postfix.size(); i++)
  {
	if (postfix[i] >= '0' && postfix[i] <= '9') 
	{
	  size_t add;
	  stNum.push(stod(&(postfix[i]), &add));
	  i += add-1;
	}
	else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
	{
	  double secondNum = stNum.pop();
	  double firstNum = stNum.pop();
	  double res = 0;
	  switch (postfix[i])
	  {
	  case '+':
		res = firstNum + secondNum;
		break;
	  case '-':
		res = firstNum - secondNum;
		break;
	  case '*':
		res = firstNum * secondNum;
		break;
	  case '/':
		res = firstNum / secondNum;
		break;
	  case '^':
		res = pow(firstNum, secondNum);
		break;
	  }
	  stNum.push(res);
	}
  }
  double res = stNum.pop();
  if (!stNum.isEmpty())
	throw exception("uncorrect expression");
  return res;
}

//atoi(); stod();