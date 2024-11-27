#include "TStack.h"
#include "TCalc.h"
#include <string>

bool check(std::string str) {
  TStack<char> s;

  for (int i = 0; i < str.size(); i++) {
	if (str[i] == '(')
	  s.push('(');
	if (str[i] == ')') 
	{
	  if (s.isEmpty()) return false;
	  s.pop();
	}
  }
  if (!s.isEmpty()) return false;
  return true;
}



int main()
{
  TCalc calc;
  // "((2 + 3) * 4) - 5"
  calc.setInfix("2^5 / (3+7)");
  //calc.setPostfix("1 2 3 + *");
  //calc.toPostfix();
  std::cout << calc.getInfix() << std::endl;
  //std::cout << calc.getPostfix() << std::endl;
  std::cout << calc.calc();
}