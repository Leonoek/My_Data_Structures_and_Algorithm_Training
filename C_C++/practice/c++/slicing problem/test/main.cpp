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

void func1(Base* b) {
    b->foo();
}

void func2(const Base& b) {
    b.foo();
}

int main() {
    Derived d;
    func1(&d);
    func2((const Base&)d);
    return 0;
}
