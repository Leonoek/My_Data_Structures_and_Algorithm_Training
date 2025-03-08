#include "Global.hpp"
#include "Base.hpp"
#include "Derived.hpp"

void UseCase1() {
	std::cout << "=== ctor ===" << std::endl;
	Derived derived("555", 55);
	std::cout << "=== cctor ===" << std::endl;
	Derived derived1 = derived;
	std::cout << "=== ctor ===" << std::endl;
	Derived derived2("666", 66);
	std::cout << "===copy assign===" << std::endl;
	derived2 = derived;
}

int main() {
	UseCase1();


	return 0;
}