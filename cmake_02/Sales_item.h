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
