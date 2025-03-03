#include <iostream>

class Base {
public:
    virtual void foo() {
        std::cout << "Base foo" << std::endl;
    }
};
class Derived : public Base {
public:
    virtual void foo() {
        std::cout << "Derived foo" << std::endl;
    }
};

void func(Base* b) {
    b->foo();
}

int main() {
    Derived d;
    func(&d);
    return 0;
}
