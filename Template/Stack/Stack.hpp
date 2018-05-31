#pragma once
#include<iostream>
#include"../Vector/Vector.hpp"
using namespace std;

template<class T,class Container>
class Stack
{
public:
    void Push(const T & x);
    void Pop();
    bool Top(T *top);
    bool Empty();

protected:
    Container _con;
};


template<class T,class Container=Vector<T>>
void Stack<T,Container>::Push(const T &x)
{
    _con.PushBack(x);
}

template<class T, class Container = Vector<T>>
void Stack<T,Container>::Pop()
{
  
    _con.PopBack();
}

template<class T, class Container = Vector<T>>
bool Stack<T,Container>::Top(T *value)
{
    if (_con.Empty())
    {
        return 0;
    }
    *value = _con.Back();
    return 1;
}

template<class T, class Container = Vector<T>>
bool Stack<T, Container>::Empty()
{
    if (!_con.Empty())
    {
        return 1;
    }
    return 0;
}
