#include "Stack.h"
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