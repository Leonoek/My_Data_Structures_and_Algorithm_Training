#include <iostream>

class MyClass
{
public:
	MyClass() {	// Ĭ�Ϲ���
		std::cout << "default &&" << std::endl;
	}

	MyClass(char& x) :var(new char(x)) { 
		std::cout << "default &" << std::endl; 
	};

	MyClass(char&& x) :var(new char(std::move(x))) {
		std::cout << "default &&" << std::endl;
	};

	MyClass& operator=(MyClass& other) {	// Ĭ�����ظ�ֵ�����
		std::cout << "operator" << std::endl;
		delete var;
		var = new char(*other.var);
		return *this;
	}

	MyClass& operator=(MyClass&& other) noexcept {	// Ĭ�������ƶ���ֵ�����
		std::cout << "move operator" << std::endl;
		delete var;
		var = new char(*other.var);
		return *this;
	}

	MyClass(const MyClass& other) {	// Ĭ�Ͽ�������
		std::cout << "copy" << std::endl;
		var = new char(*other.var);
	}

	MyClass(MyClass&& other): var(new char(std::move(*other.var))) {	// Ĭ���ƶ����캯��
		std::cout << "rvalue copy" << std::endl;
	}

	~MyClass() {	// Ĭ������
		delete var;
	}

private:
	char* var;
};


int main() {
	MyClass test('A');
	std::cout << "**************" << std::endl;
	MyClass test2('B');
	std::cout << "**************" << std::endl;
	MyClass test3(test2);
	std::cout << "**************" << std::endl;
	MyClass test4(std::move(test3));
	std::cout << "**************" << std::endl;
	MyClass test5;
	test5 = std::move(MyClass('c'));
	std::cout << "**************" << std::endl;
	MyClass test6(MyClass('c'));
	std::cout << "**************" << std::endl;
	test2 = test;
	return 0;
}