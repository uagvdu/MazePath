#pragma once 
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class Stack
{
public:
	Stack()
		:_a(new T[1])
		,_sz(0)
		,_capacity(0)
	{}
	~Stack()
	{
		if(_a)
		{
			delete[] _a;
			_sz = 0;
			_capacity = 0;

		}
	}
public:
	void Push(const T& d);
	void CheckCapacity();	
	bool Empty();
	void Pop();
	T& Top();
	void Dislplay();
protected:
	T* _a;
	int _sz;
	int _capacity;
};

template<class T>

void Stack<T>::CheckCapacity ()
{
	if(_sz == _capacity )
	{
		T* tmp =new T[_capacity * 2+ 3];
		for(int i = 0; i < _sz;i++)
		{
			tmp[i] = _a[i];
		}
		delete[] _a;
		_capacity = _capacity * 2 + 3;
		_a = tmp;
	}
}

template<class T>

void Stack<T>::Push(const T& d)
{
	CheckCapacity();
	_a[_sz] = d;
     _sz++;
}



template<class T>

void Stack<T>::Pop()
{
	assert(_sz > 0);
	_sz--;

}

template<class T>

T& Stack<T>::Top()
{
	return _a[_sz-1];
}


template<class T>

bool Stack<T>::Empty()
{
	return _sz == 0;
}

template<class T>
void Stack<T>::Dislplay ()
{
	for(int i = 0;i<_sz ;i++)
	{
		cout<<_a[i]<<" ";
	}
	cout<<endl;
}