#include <iostream>

class Test {
    int x;
public:
    Test(int x) : x(x) {}

    auto operator++() {
        x += 1;
        return x-1;
    }

    auto operator++(int) {
        x += 1;
        return x;
    }

    void setX (int x) {
        this->x = x;
    }

    int getX() {
        return x;
    }

};
int main(){
    int a = 2;
    Test t(a);
    std::cout << a++ << std::endl;
    std::cout << ++a << std::endl;
    std::cout << t++ << std::endl;
    t.setX(t.getX() - 1);
    std::cout << ++t << std::endl;
}