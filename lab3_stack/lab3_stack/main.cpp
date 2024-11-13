#include "TStack.h"
#include "TCalc.h"
#include <string>

bool check(string str) {
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
  TCalc<double> calc;
  // "((2 + 3) * 4) - 5"
  calc.setInfix("((5 + 3) * 1488) - (5+1) * 1488 ");
  //calc.setPostfix("1 2 3 + *");
  calc.toPostfix();
  cout << calc.getInfix() << endl;
  cout << calc.getPostfix() << endl;
  cout << calc.calc();
}