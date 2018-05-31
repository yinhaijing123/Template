#define _CRT_SECURE_NO_WARNINGS
#include"Stack.hpp"
void Test()
{
    Stack<int, Vector<int>> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    int top;
    bool ret=s.Top(&top);
    cout << "top=" << top << endl;
    cout << "expect ret is 1,actual is " << ret << endl;


    s.Pop();
    s.Pop();

    ret=s.Top(&top);
    cout << "top=" << top << endl;
    cout << "expect ret is 1,actual is " << ret << endl;


    s.Pop();
    s.Pop();

    ret=s.Top(&top);
    cout << "top=" << top << endl;
    cout << "expect ret is 0,actual is " << ret << endl;

}

int main()
{
    Test();

    system("pause");
    return 0;
}