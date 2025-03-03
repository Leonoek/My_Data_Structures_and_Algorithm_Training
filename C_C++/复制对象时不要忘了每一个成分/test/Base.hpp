#pragma once
#include "Global.hpp"

class Base {
public:
	explicit Base(std::string name = "Unknow") : name_(std::move(name)) {
		std::cout << "[Base(std::string)] name:" << name_ << std::endl;
	}

	Base(const Base& rhs) {
		std::cout << "[ Base(const Base&)] base.name:" << rhs.name_ << std::endl;
		this->name_ = rhs.name_;
	}

	Base& operator=(const Base& rhs) {
		std::cout << "[Base operator=(const Base&)] rhs.name:" << rhs.name_ << std::endl;
		this->name_ = rhs.name_;
		return *this;
	}

protected:
	std::string name_;
};