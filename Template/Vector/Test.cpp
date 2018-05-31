#define _CRT_SECURE_NO_WARNINGS
#include"Vector.hpp"
#define TEST_HEADER printf("========================%s======================\n",__FUNCTION__)

void TestStructor()
{
    TEST_HEADER;
    Vector <int> v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    v1.Print();

    Vector<int> v2(v1);
    v2.Print();
    v2.PushBack(5);
    v2.Print();
}
void TestPop()
{
    TEST_HEADER;
    Vector <int> v1;
    v1.PushBack(1);
    v1.PushBack(2);
    v1.PushBack(3);
    v1.PushBack(4);
    v1.Print();
    v1.PopBack();
    v1.Print();
    v1.PopBack();
    v1.Print();
    v1.PopBack();
    v1.Print();
    v1.PopBack();
    v1.Print();
    v1.PopBack();
    v1.Print();

}

void TestFind()
{
    TEST_HEADER;
    Vector <string> v1;
    v1.PushBack("11111111111111111111111111111111111111111111111111");  
    v1.PushBack("222");
    v1.PushBack("333");
    v1.PushBack("444");
    v1.Print();
    Vector <string>v2(v1);
    v2.Print();

    size_t ret=v1.Find("222");
    cout << "expect is 1,actual is " << ret << endl;

    ret = v1.Find("2222");
    cout << "expect is 429бнбн,actual is " << ret << endl;
}

int main()
{

    TestStructor();
    TestPop();
    TestFind();

    system("pause");
    return 0;
}