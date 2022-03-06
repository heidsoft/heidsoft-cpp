#include<iostream>
using namespace std;
// 编译cc -DNDEBUG main.cpp
//
int main()
{
#ifndef NDEBUG
cerr << "starting main" <<endl;
#endif
}