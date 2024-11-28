#include "TCalc.h"

int TCalc::priority(Operation op)
{
  int priority = 0;
  switch (op)
  {
  case OPN:
  case CLS:
	break;
  case PLUS:
  case MINUS:
	priority = 1;
	break;
  case MULT:
  case DIV:
	priority = 2;
	break;
  case POW:
	priority = 3;
	break;
  case SIN:
  case COS:
  case EXP:
	priority = 4;
	break;
  default:
	throw std::exception("isn't opertion");
	break;
  }
  return priority;
}

bool TCalc::isOperation(char ch) 
{
  return ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^';
}

bool TCalc::isFunction(const std::string str)
{
  return str == "sin" || str == "cos" || str == "exp";
}

Operation TCalc::getOperation(const std::string str)
{
  Operation op;
  if (str == "+") op = PLUS;
  else if (str == "-") op = MINUS;
  else if (str == "*") op = MULT;
  else if (str == "/") op = DIV;
  else if (str == "^") op = POW;
  else if (str == "sin") op = SIN;
  else if (str == "cos") op = COS;
  else if (str == "exp") op = EXP;
  else throw std::exception("it's not operation");
  return op;
}

double TCalc::calcOperation(Operation op)
{
  double res = 0.0;
  double first = 0.0;
  double second = 0.0;
  switch (op)
  {
  case PLUS:
	second = stNum.pop();
	first = stNum.pop();
	res = first + second;
	break;
  case MINUS:
	second = stNum.pop();
	first = stNum.pop();
	res = first - second;
	break;
  case MULT:
	second = stNum.pop();
	first = stNum.pop();
	res = first * second;
	break;
  case DIV:
	second = stNum.pop();
	first = stNum.pop();
	res = first / second;
	break;
  case POW:
	second = stNum.pop();
	first = stNum.pop();
	res = std::pow(first, second);
	break;
  case SIN:
	first = stNum.pop();
	res = std::sin(first);
	break;
  case COS:
	first = stNum.pop();
	res = std::cos(first);
	break;
  case EXP:
	first = stNum.pop();
	res = std::exp(first);
	break;
  }
  return res;
}

TCalc::TCalc() :stNum(), stChar(), stOperation()
{
  infix = "";
  postfix = "";
}

void TCalc::setInfix(std::string _infix)
{
  infix = _infix;
  //временно
  stNum = TStack<double>(infix.size());
  stChar = TStack<char>(infix.size());
  stOperation = TStack<Operation>(infix.size()/2);
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

//void TCalc::toPostfix()
//{
//  std::string s = "(" + infix + ")";
//  for (int i = 0; i < s.size(); i++)
//  {
//	if (s[i] == '(')
//	  stChar.push(s[i]);
//	else if (s[i] == ')')
//	{
//	  char a = stChar.pop();
//	  while (a != '(')
//	  {
//		postfix += ' ';
//		postfix += a;
//		a = stChar.pop();
//	  }
//	}
//	else if (s[i] >= '0' && s[i] <= '9' || s[i] == '.')
//	{
//	  postfix += s[i];
//	  //postfix += ' ';
//	}
//	else if (isOperation(s[i]))
//	{
//	  postfix += ' ';
//	  while (priority(s[i]) <= priority(stChar.top()))
//	  {
//		postfix += stChar.pop();
//		postfix += ' ';
//	  }
//	  stChar.push(s[i]);
//	}
//  }
//}


double TCalc::postfixCalc()
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
	if (s[i] == '(') {
	  if (s[i + 1] == '-')
	  {
		std::size_t add;
		stNum.push(std::stod(&(s[i+1]), &add));
		i += add + 1; 
	  }
	  else 
		stOperation.push(OPN);
	}
	else if (s[i] == ')')
	{
	  Operation op = stOperation.pop();
	  while (op != OPN)
	  {
		double res = calcOperation(op);
		stNum.push(res);
		op = stOperation.pop();
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
	  Operation op = getOperation(s.substr(i, 1));
	  while (priority(op) <= priority(stOperation.top()))
	  {
		double res = calcOperation(stOperation.pop());
		stNum.push(res);
	  }
	  stOperation.push(op);
	}
	else if (isFunction(s.substr(i, 3)))
	{
	  Operation op = getOperation(s.substr(i, 3));
	  while (priority(op) <= priority(stOperation.top()))
	  {
		double res = calcOperation(stOperation.pop());
		stNum.push(res);
	  }
	  stOperation.push(op);
	}
  }
  double res = stNum.pop();
  if (!stNum.isEmpty())
	throw std::exception("uncorrect expression");
  return res;
}