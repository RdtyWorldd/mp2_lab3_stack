#pragma once
#include <iostream>

using namespace std;

#define STACK_MAX_SIZE 100

template <class T>
class TStack {
  size_t maxSize; // максимальный размер стека
  size_t lastNum; //индекс последнего элемента
  
  T* pMem; //указатель на память
public:
  TStack(size_t maxSize = 5); // конструктор 
  TStack(const TStack<T>& stack); // конструктор копирования
  ~TStack(); //деструктор
  
  bool isEmpty() const;
  bool isFull() const;

  T pop();
  void push(T obj);
  T top() const;

  void clear();
  //операторы
  TStack& operator= (const TStack<T>& stack);
  bool operator== (const TStack<T>& stack);
  bool operator!= (const TStack<T>& stack);
  //операторы вывода
  friend ostream& operator<< (ostream& out, const TStack<T>& stack);
  friend istream& operator>> (istream& in, TStack<T>& stack);
};

template <class T>
TStack<T>::TStack(size_t _maxSize) 
{
  if (_maxSize < 1 || _maxSize >= STACK_MAX_SIZE )
	throw out_of_range("maxSize is out of range");
  maxSize = _maxSize;
  lastNum = -1;
  pMem = new T[maxSize];
}

template <class T>
TStack<T>::TStack(const TStack<T>& stack) 
{
  maxSize = stack.maxSize;
  lastNum = stack.lastNum;
  pMem = new T[maxSize];
  for (int i = 0; i <= lastNum; i++)
	pMem[i] = stack.pMem[i];
}

template<class T>
inline TStack<T>::~TStack()
{
  delete[] pMem;
}

template<class T>
inline bool TStack<T>::isEmpty() const
{
  return lastNum != -1;
}

template<class T>
inline bool TStack<T>::isFull() const
{
  return lastNum+1 == maxSize;
}

template <class T>
T TStack<T>::pop()
{
  if (isEmpty()) throw exception("stack is empty");
  T tmp = pMem[lastNum];
  lastNum--;
  return tmp;
}

template <class T>
void TStack<T>::push(T obj) {
  if (isFull()) throw exception("stack overflow");
  lastNum++;
  pMem[lastNum] = obj;
}

template<class T>
inline T TStack<T>::top() const
{
  return pMem[lastNum];
}

template<class T>
inline void TStack<T>::clear()
{
  lastNum = -1;
}

template <class T>
TStack<T>& TStack<T>::operator= (const TStack<T>& stack) 
{
  if (this != &stack) 
  {
	if (maxSize != stack.maxSize) 
	{
	  T* tmp = new T[stack.maxSize];
	  delete pMem;
	  maxSize = stack.maxSize;
	  pMem = tmp;
	}
	lastNum = stack.lastNum;

	for (int i = 0; i <= lastNum; i++)
	  pMem[i] = stack.pMem[i];
  }
  return *this;
}

//template<class T>
//inline bool TStack<T>::operator==(const TStack<T>& stack)
//{
//  return false;
//}
//
//template<class T>
//inline bool TStack<T>::operator!=(const TStack<T>& stack)
//{
//  return false;
//}

