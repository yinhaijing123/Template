#define _CRT_SECURE_NO_WARNINGS
#include"List.hpp"

#define TEST_HEADER printf("=======================%s=====================\n",__FUNCTION__)

void TestPush()
{
    TEST_HEADER;
    List<int> i;
    List<char> c;
    List<string> s;
    i.PushBack(1);
    i.PushBack(2);
    i.PushFront(3);
    i.PushFront(4);
    i.Print();

    c.PushBack('a');
    c.PushBack('b');
    c.PushFront('c');
    c.PushFront('d');
    c.Print();
}

void TestPop()
{
    TEST_HEADER;
    List<int> i;
    List<char> c;
    List<string> s;

    i.PushBack(1);
    i.PushBack(2);
    i.PushFront(3);
    i.PushFront(4);
    i.Print();

    s.PushBack("1111111111111111111111111111");
    s.PushBack("2222");
    s.PushBack("3333");
    s.PushBack("4444");
    s.Print();
    
    i.PopBack();
    i.PopFront();
    i.PopBack();
    i.PopFront();
    i.PopFront();
    i.Print();

    s.PopBack();
    s.PopFront();
    s.PopBack();
    s.PopFront();
    s.PopBack();
    s.Print();
}
int main()
{
    TestPush();
    TestPop();
   
    system("pause");
    return 0;
}