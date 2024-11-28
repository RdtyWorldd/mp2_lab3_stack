#pragma once
#include <string>
#include "TStack.h"
#include <cmath>

//using namespace std;

enum Operation
{
  OPN,
  CLS,
  PLUS,
  MINUS,
  MULT,
  DIV,
  POW,
  SIN,
  COS,
  EXP
};

class TCalc {
  std::string infix;
  std::string postfix;

  TStack<double> stNum;
  TStack<char> stChar;
  TStack<Operation> stOperation;

  int priority(Operation op);
  bool isOperation(char ch);
  bool isFunction(const std::string str);
  Operation getOperation(const std::string str);
  double calcOperation(Operation op);

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
