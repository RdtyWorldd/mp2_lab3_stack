#include "TCalc.h"

int TCalc::priority(char action)
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
	throw std::exception("not operation");
	break;
  }
  return priority;
}

bool TCalc::isOperation(char ch) 
{
  return ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^';
}

TCalc::TCalc() :stNum(), stChar()
{
  infix = "";
  postfix = "";
}

void TCalc::setInfix(std::string _infix)
{
  infix = _infix;
  //временно
  stNum = TStack<double>(infix.size() / 2);
  stChar = TStack<char>(infix.size() / 2);
}

std::string TCalc::getInfix()
{
  return infix;
}

void TCalc::setPostfix(std::string _postfix)
{
  postfix = _postfix;
}

std::string TCalc::getPostfix()
{
  return postfix;
}

void TCalc::toPostfix()
{
  std::string s = "(" + infix + ")";
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
	else if (s[i] >= '0' && s[i] <= '9' || s[i] == '.')
	{
	  postfix += s[i];
	  //postfix += ' ';
	}
	else if (isOperation(s[i]))
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

double TCalc::tcalc()
{
  stNum.clear();
  for (int i = 0; i < postfix.size(); i++)
  {
	if (postfix[i] >= '0' && postfix[i] <= '9')
	{
	  std::size_t add;
	  stNum.push(std::stod(&(postfix[i]), &add));
	  i += add - 1;
	}
	else if (isOperation(postfix[i]))
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
	throw std::exception("uncorrect expression");
  return res;
}

double TCalc::calc()
{
  stNum.clear();
  stChar.clear();
  std::string s = "(" + infix + ")";
  for (int i = 0; i < s.size(); i++) 
  {
	if (s[i] == '(')
	  stChar.push(s[i]);
	else if (s[i] == ')')
	{
	  char a = stChar.pop();
	  while (a != '(')
	  {
		//подсчет операций
		double secondNum = stNum.pop();
		double firstNum = stNum.pop();
		double res = 0;
		switch (a)
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
		a = stChar.pop();
	  }
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
	  std::size_t add;
	  stNum.push(std::stod(&(s[i]), &add));
	  i += add - 1;
	}
	else if (isOperation(s[i]))
	{
	  while (priority(s[i]) <= priority(stChar.top()))
	  {
		double secondNum = stNum.pop();
		double firstNum = stNum.pop();
		double res = 0;
		switch (stChar.pop())
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
	  stChar.push(s[i]);
	}
  }
  double res = stNum.pop();
  if (!stNum.isEmpty())
	throw std::exception("uncorrect expression");
  return res;
}