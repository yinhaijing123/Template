#pragma once
#include<iostream>
#include<string>
#include<assert.h>

using namespace std;

//ֻ�б����õĳ�Ա�������Ż������Щ������ʵ��������
//ģ���಻֧�ַ���ģ��
template<class T>
struct ListNode
{
    T _data;
    ListNode<T> *_next;                     //ListNodeΪģ�������ͣ���ListNode<T>Ϊ�����ͣ�ListNodeΪ������
    ListNode<T> *_prev;

    ListNode(const T& data)              
        :_data(data)                        //ִ�иò��裬��ȥ����T���͵Ĺ��캯��
        , _next(NULL)
        , _prev(NULL)
    {}
};

template<class T>
class List
{
    typedef ListNode<T> Node;
public:
    List();
    List(const List<T>& l);
    List<T>& operator=( List<T> l);
    ~List();
    void Clear();

    void PushBack(const T& x);
    void PopBack();
    void PushFront(const T& x);
    void PopFront();
    void Insert( Node *pos,const T& x);
    void Erase(Node *pos);
    bool Empty();
    T Head();

    void Print();

protected:
    Node *_head;
};

template<class T>
List<T>::List()
    :_head(new Node(T()))
{
    _head->_next = _head;
    _head->_prev = _head;
}

template<class T>
List<T>::List(const List<T>& l)
    :_head(new Node<T>(T()))
{
    _head->_next = _head;
    _head->_prev = _head;

    Node *cur = l._head->_next;
    while (cur != l._head)
    {
        PushBack(cur->_data);
        cur = cur->_next;
    }
}

template<class T>
List<T>& List<T>::operator=(List<T> l)
{
    if (this != &l)
    {
        swap(_head, l._head);
    }
    return *this;
}

template<class T>
List<T>::~List()
{
    Clear();
    delete _head;
}

template<class T>
void List<T>::Clear()
{
    Node *cur = _head->_next;
    while (cur != _head)
    {
        Node *to_delete = cur;
        cur = cur->_next;
        delete to_delete;
    }
    _head->_next = _head;              //�������ǻָ�������״̬
    _head->_prev = _head;
}

template<class T>
void List<T>::PushBack(const T& x)
{
    Node *new_node = new Node(x);
    Node *pre = _head->_prev;
    pre->_next = new_node;
    new_node->_prev = pre;
    new_node->_next = _head;
    _head->_prev = new_node;
}

template<class T>
void List<T>::PopBack()
{
    if (_head == _head->_next)
    {
        return;
    }

    Node *to_delete = _head->_prev;
    Node *prev = to_delete->_prev;
    prev->_next = _head;
    _head->_prev = prev;
    delete to_delete;
}

template<class T>
void List<T>::PushFront(const T& x)
{
    Node *new_node = new Node(x);
    Node *next = _head->_next;
    _head->_next = new_node;
    new_node->_prev = _head;
    new_node->_next = next;
    next->_prev = new_node;
}

template<class T>
void List<T>::PopFront()
{
    if (_head == _head->_next)
    {
        return;
    }

    Node *to_delete = _head->_next;
    Node *next = to_delete->_next;
    _head->_next = next;
    next->_prev = _head;
    delete to_delete;
}

template<class T>
void List<T>::Insert(Node *pos, const T& x)
{
    Node *new_node = new Node(x);
    Node *next = pos->_next;
    pos->_next = new_node;
    new_node->_prev = pos;
    new_node->_next = next;
    next->_prev = new_node;
}

template<class T>
void List<T>::Erase(Node *pos)
{
    assert(pos != _head);

    Node *prev = pos->_prev;
    Node *next = pos->_next;
    prev->_next = next;
    next->_prev = prev;
    delete pos;
}

template<class T>
void List<T>::Print()
{
    Node *cur = _head->_next;
    while (cur != _head)
    {
        cout << (cur->_data)<<"  " ;
        cur = cur->_next;
    }
    cout << endl;
}

template<class T>
T List<T>::Head()
{
    assert(_head);
    if (_head->_next != NULL)
    {
        return _head->_next->_data;
    }
    return T();
}

template<class T>
bool List<T>::Empty()
{
    return _head == _head->_next;
}


