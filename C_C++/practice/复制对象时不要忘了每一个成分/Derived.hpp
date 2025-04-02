#pragma once
#include "Global.hpp"
#include "Base.hpp"

class Derived : public Base {
public:
	friend std::ostream &operator<<(std::ostream& os, const Derived& derived);

	Derived(std::string name, int value) : Base(std::move(name)), value_(value) {
		std::cout << "Derived(string, int) :" << *this << std::endl;
	}

	Derived(const Derived& derived) : Base(derived), value_(derived.value_) {
		std::cout << "Derived(const Derived &): " << *this << std::endl;
	}

	Derived& operator=(const Derived& derived) {
		Base::operator=(derived);
		value_ = derived.value_;
		std::cout << "Derived &operator=(const Derived &): " << *this << std::endl;
		return *this;
	}

private:
	int value_;
};


inline std::ostream& operator<<(std::ostream& os, const Derived& derived) {
	os << "Derived [ value_ : " << derived.value_ << ", Base [ name_ : " << derived.name_ << "]";
	return os;
}