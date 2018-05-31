#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string>
using namespace std;

//顺序表
template <class T>
class Vector
{
public:
    Vector();
    Vector(const Vector<T> &v);
    Vector<T> operator=(const Vector<T> &v);
    ~Vector();

    void Swap(Vector<T>& v);
    void PushBack(T x);
    void PopBack();
    void Insert(size_t pos, T x);
    void Erase(size_t pos);
    size_t Find(T x);
    const size_t Size()const;
    const size_t Capacity() const;
    void Print();
    bool Empty();
    T& Back();

protected:
    void Expand(size_t n);
protected:
    T * _first;
    T *_finish;
    T *_endofstorage;
};

///////////////////////////////////////////////////////////////////////////
//c++标准明确表示，当一个模板不被用到的时侯它就不该被实例化出来
template<class T>
Vector<T>::Vector()
    :_first(NULL)
    ,_finish(NULL)
    ,_endofstorage(NULL)
{}

template<class T>
Vector<T>::Vector(const Vector<T> &v)
    :_first(new T[v.Size()])
{
    //方法一：利用memcpy()函数实现拷贝，但若T为涉及深浅拷贝的自定义类型，如：string类型,则可能出现错误。
    //        原因：memcpy()是根据字节数进行拷贝的。
    memcpy(_first, v._first, v.Size() * sizeof(T));


    //方法二：根据T类型进行按对象赋值，而非按字节。
    /* for (size_t i = 0; i < v.Size(); i++)
    {
    _first[i] = v._first[i];
    }*/

    _finish = _first + v.Size();
    _endofstorage = _first + v.Size();
}

template<class T>
void Vector<T>::Swap(Vector<T>& v)
{
    swap(_first, v._first);
    swap(_finish, v._finish);
    swap(_endofstorage, v._endofstorage);
}

template<class T>
Vector<T> Vector<T>::operator=(const Vector<T> &v)
{
    if (this != &v)
    {
        Vector v1(v);
        Swap(&v1);
    }
}

template<class T>
Vector<T>::~Vector()
{
    delete[]_first;
    _first = _finish = _endofstorage = NULL;
}

template<class T>
void Vector<T>::Expand(size_t n)
{
    if (n > Capacity())
    {
        T * tmp = new T[n];
        size_t size = Size();          //用size记录传入的size，防止_first被改以后，Size()计算错误。
        for (size_t i = 0; i < size; i++)
        {
            tmp[i] = _first[i];
        }
        _first = tmp;
        _finish = _first + size;
        _endofstorage = _first + n;
    }
}

template<class T>
void Vector<T>::PushBack(T x)
{
    /*if (Size() == Capacity())
    {
        if (Capacity() == 0)
        {
            Expand(3);
        }
        else
        {
            Expand(Capacity() * 2);
        }
    }
    *_finish = x;
    ++_finish;*/
    Insert(Size(), x);
}

template<class T>
void Vector<T>::PopBack()
{
   /* if (Size() == 0)
    {
        cout << "Vector为空" << endl;
        return;
    }
    --_finish;*/
    Erase(Size() - 1);
}

template<class T>
void Vector<T>::Insert(size_t pos, T x)
{
    assert(pos <= Size());
    if (Size() >= Capacity())
    {
        if (Capacity() == 0)
        {
            Expand(3);
        }
        else
        {
            Expand(Capacity() * 2);
        }
    }
   /* for (int i = Size() - 1; i >= (int)pos; i--)              //方法一：注意i和pos的比较
    {
        _first[i + 1] = _first[i];
    }*/

    T *end = _finish - 1;
    while (end >= _first + pos)
    {
        *(end + 1) = *end;
        end--;
    }
    _first[pos] = x;
    ++_finish;
}

template<class T>
void Vector<T>::Erase(size_t pos)
{
    if (Size() == 0)
    {
        cout << "Vector为空" << endl;
        return;
    }
    assert(pos < Size());
    for (int i = pos; i < Size() - 1; i++)
    {
        _first[i] = _first[i + 1];
    }
    --_finish;
}

template<class T>
size_t Vector<T>::Find(T x)
{
    for (size_t i = 0; i < Size(); i++)
    {
        if (_first[i] == x)
        {
            return i;
        }
    }
    return -1;
}

template<class T>
const size_t Vector<T>::Size()const
{
    return _finish - _first;
}

template<class T>
const size_t Vector<T>::Capacity() const
{
    return _endofstorage - _first;
}

template<class T>
void Vector<T>::Print()
{
    for (size_t i = 0; i < Size(); i++)
    {
        cout << _first[i] << ' ';
    }
    cout << endl;
}

template<class T>
bool Vector<T>::Empty()
{
    if (Size() == 0)
    {
        return 1;
    }
    return 0;
}

template<class T>
T& Vector<T>::Back()
{
    return _first[Size()-1];
}
