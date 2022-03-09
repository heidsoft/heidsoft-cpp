#include<iostream>
using namespace std;
// 编译cc -DNDEBUG main.cpp
// 预处理器
int main()
{
#ifndef NDEBUG
cerr << "starting main" <<endl;
#endif
}