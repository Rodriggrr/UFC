#include <iostream>
#include <memory>
struct Foo{
    int x = 4;
};

using Ptr = std::shared_ptr<Foo>;

int foo(void* p)
{
    return ((Foo*)p)->x;
}

int main()
{
    void* p;
    p = new Foo;
    std::cout << foo(p);
}