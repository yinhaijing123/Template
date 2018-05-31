#pragma once
#include<iostream>
//#include"D:\Code\c++\Template\List\List.hpp"                     //绝对路径包含头文件
#include"../List/List.hpp"                                     //相对路径包含头文件
using namespace std;

template<class T,class Container=List<T>>
class Queue
{
public:
    Queue()
        :_con()
    {}

    void Push(const T & x);
    void Pop();
    bool Head(T &value);
    bool Empty();

private:
    Container _con;
};

template<class T, class Container = List<T>>
void Queue<T, Container>:: Push(const T & x)
{
    _con.PushBack(x);
}

template<class T, class Container = List<T>>
void Queue<T, Container>::Pop()
{
    _con.PopFront();
}

template<class T, class Container = List<T>>
bool Queue<T, Container>::Head(T& value)
{
    if (_con.Empty())
    {
        return 0;
    }
    value = _con.Head();
    return 1;
}

template<class T, class Container = List<T>>
bool Queue<T, Container>::Empty()
{
    return _con.Empty();
}