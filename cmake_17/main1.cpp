#include <iostream>     
using namespace std;

class Foo
 {
   public:
   Foo ( )
   {
      cout << "constructor Foo\n";
   }               
};

class Bar
 {
   public:
   Bar ( Foo )
   {
      cout << "constructor Bar\n";
   }
};

int main()
{
   /* 1 */ Foo* foo1 = new Foo ();
   /* 2 */ Foo* foo2 = new Foo;
   /* 3 */ Foo foo3;
   /* 4 */ //Foo foo4 = Foo::Foo(); //  不合法

   /* 5 */ Bar* bar1 = new Bar ( *new Foo() );
   /* 6 */ Bar* bar2 = new Bar ( *new Foo );
   /* 7 */ //Bar* bar3 = new Bar ( Foo foo5 ); //  不合法
   /* 8 */ //Bar* bar3 = new Bar ( Foo::Foo() ); //  不合法

   return 1;
}