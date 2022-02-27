// 引入io操作
#include <iostream>
int main()
{

    std::cout <<"Enter two numbers:" <<std::endl;
    int v1,v2;
    // 输入两个数字
    std::cin >>v1 >>v2;
    // 输出两个数字之和
    std::cout<<"The sum of " <<v1 << " and " << v2
    << " is " << v1 + v2 << std::endl;
    return 0;
}