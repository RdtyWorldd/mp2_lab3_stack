#pragma once
#include <string>
#include "TStack.h"

//using namespace std;

class TCalc {
  std::string infix;
  std::string postfix;

  TStack<double> stNum;
  TStack<char> stChar;

  int priority(char action);
  bool isOperation(char ch);
public:
  TCalc();

  void setInfix(std::string _infix);
  std::string getInfix();

  void setPostfix(std::string _postfix);
  std::string getPostfix();

  void toPostfix();
  
  double postfixCalc();

  double calc();
};
