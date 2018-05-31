#define _CRT_SECURE_NO_WARNINGS
#include"Queue.hpp"

void Test()
{
    Queue<int, List<int>> q;
    int head;
    bool ret = q.Head(head);
    cout << "ret expect is 0,actual is " << ret << endl;
    cout << "queue head is " << head << endl;

    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);

    q.Pop();
    ret = q.Head(head);
    cout << "ret expect is 1,actual is " << ret << endl;
    cout << "queue head expect is 2,actual is " << head<<endl;

    Queue<char, List<char>> qc;

    char head1;
    ret = qc.Head(head1);
    cout << "ret expect is 0,actual is " << ret << endl;
    cout << "queue head is " << head1 << endl;

    qc.Push('a');
    qc.Push('b');
    qc.Push('c');
    qc.Push('d');
    ret = qc.Head(head1);
    cout << "ret expect is 1,actual is " << ret << endl;
    cout << "queue head expect is a,actual is " << head1 << endl;
}

int main()
{
    Test();

    system("pause");
    return 0;
}