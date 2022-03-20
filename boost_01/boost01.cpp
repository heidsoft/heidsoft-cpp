#include<iostream>
#include<boost/filesystem.hpp>
////clang++ -std=c++17 boost01.cpp -o list_dir -lboost_system -lboost_filesystem
////编译参数 如上
////boost 头文件路径 /usr/local/include/boost/filesystem.hpp
////boost 标准库路径 /usr/local/lib/libboost*
int main(){
    //采用 "cppStandard": "c++11"
    //https://www.oreilly.com/library/view/learning-boost-c/9781783551217/apas04.html
    //获取当前路径
    /*
     C++11, you can use the auto keyword to ask the compiler to deduce the 
     type of a declared variable using the type of the expression it is initialized with. 
     Thus, the preceding tedium is replaced by the following:
     C++11 中，可以使用 auto 关键字要求编译器使用用于初始化已声明变量的表达式的类型来推断该变量的类型。
     因此，前面的乏味被替换为以下内容：
     */
    auto path = boost::filesystem::current_path();
    std::cout << path << "\n";
    //输出目录下的内容
 	for(auto &entry : boost::filesystem::directory_iterator(path))
 	{
 		std::cout << entry << std::endl;
 	}
}

