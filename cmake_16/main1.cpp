#include "a.h"
// C++ code 与 C 代码混合
extern "C" void f(int); // one way
void f(int a){
    printf("call f: %d\n",a);    
}

extern "C" {    // another way
    int g(double);
    double h();
};

int g(double a){
    printf("call g: %f\n",a);
    return a;
}

double h(){
    printf("call h\n");
    return 1;
}

void code(int i, double d)
{
    f(i);
    int ii = g(d);
    double dd = h();
    // ...
}

class CppObject
{
private:
    /* data */
public:
    CppObject(/* args */);
    ~CppObject();
};

CppObject::CppObject(/* args */)
{
   printf("call CppObject \n");
}

CppObject::~CppObject()
{
    // 内存清除 
    printf("call ~CppObject \n");
}


int main(int argc, const char * argv[]) {
    CppObject *cObject1 = new CppObject;
    delete cObject1;
    printf("class todo\n");
    code(1,2.0);
}