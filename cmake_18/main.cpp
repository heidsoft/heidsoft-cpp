#include <iostream>
#include <stdio.h>

using namespace std;

// 我的函数指针
// 为void类型，转任何类型
typedef void (*Func)();

// 我的基类
class Base
{
private:
    /* data */
public:
    Base(/* args */);
    virtual void func1();
    virtual void func2();
    virtual void func3();
    ~Base();
};

Base::Base(/* args */)
{
}

void Base::func1(){
    cout << "Base::fun1()" << endl;
}

void Base::func2(){
    cout << "Base::fun2()" << endl;
}

void Base::func3(){
    cout << "Base::fun3()" << endl;
}

Base::~Base()
{
}

// 我的子类，继承了Base
class Child : public Base
{
private:
    /* data */
public:
    Child(/* args */);
    void func1();
    void func2();
    void func3();
    ~Child();
};

Child::Child(/* args */)
{
    //Todo
}

Child::~Child()
{
}

// 子类方法实现
void Child::func1()
{
    cout << "Child::fun1()" << endl;
}

// 子类方法实现
void Child::func2()
{
    cout << "Child::fun1()" << endl;
}

// 子类方法实现
void Child::func3()
{
    cout << "Child::fun1()" << endl;
}

Func getAddr(void* obj,unsigned int offset)
{
    cout<<"======================="<<endl;
    void* vptr_addr = (void *)*(unsigned long *)obj;  //64位操作系统，占8字节，通过*(unsigned long *)obj取出前8字节，即vptr指针
    printf("vptr_addr:%p\n",vptr_addr);

    /**
     * @brief 通过vptr指针访问virtual table，因为虚表中每个元素(虚函数指针)在64位编译器下是8个字节，因此通过*(unsigned long *)vptr_addr取出前8字节，
     * 后面加上偏移量就是每个函数的地址！
     */
    void* func_addr = (void *)*((unsigned long *)vptr_addr+offset);
    printf("func_addr:%p\n",func_addr);
    return (Func)func_addr;
}

//https://cloud.tencent.com/developer/article/1510207
int main(int argc, char const *argv[])
{
    /* 构造实例 */
    Base *base = new Base();
    base->func1();
    base->func2();
    base->func3();

    //基类实例
    Base ptr;
    ptr.func1();
    ptr.func2();
    ptr.func3();

    //子类实例
    Child child1;
    child1.func1();
    child1.func2();
    child1.func3();

    // 父类引用，指向子类
    Base *pchild = new Child(); // 基类指针指向派生类实例
    pchild->func1();
    pchild->func2();
    pchild->func3();

    Base &pBase = ptr; // 基类引用指向基类实例
    Base &pChild = child1; // 基类引用指向派生类实例

    // 虚函数表，地址相差多少
    Func f1 = getAddr(base, 0);
    (*f1)();
    Func f2 = getAddr(base, 1);
    (*f2)();
    
    delete base;
    return 0;
}
