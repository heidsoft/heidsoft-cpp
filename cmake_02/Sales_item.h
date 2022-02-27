#include <string>
// 定义销售商品类
// 1. 类体可以为空，类体定义组成该类型的数据和操作
// 2. 数据称为数据成员
// 3. 类可以包含0个 到 多个private 或 public访问标号
// 4. 访问标号控制类成员在类外部是否可访问。
// 5. 使用该类的代码可能只能访问public 成员
// 6. 定义了类，也就是定义了一种新的类型
// 7. 类名就是该类型的名字
// 8. 类不是在类定义里定义数据成员时初始化数据成员
// 9. 通过称为构造函数的特殊成员函数控制初始化
// 10. 类的头文件，名字在使用前必须先声明或定义
// 11. 由多个文件组成的程序需要一种方法连接名字的使用和声明，c++通过头文件实现
// 12. 头文件一般包含类的定义，extern变量的声明和函数声明。
// 13. 使用或定义这些实体的文件要包含适当的头文件。
// 14. 设计头文件，记住定义和声明的区别很重要，定义只能出现一次，而声明可以出现多次
// 15. extern int ival = 10 ;  初始化了，所以是定义
// 16. double rate;  没有extern，所以是定义
class Sales_item
{
private:
    /* data */
    std::string isbn; // 图书编号
    unsigned units_sold;// 销售单位
    double revenue; //收入

public:
    Sales_item(/* args */);
    ~Sales_item();
};

Sales_item::Sales_item(/* args */)
{
}

Sales_item::~Sales_item()
{
}
