#include <iostream>

class String {
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string) {
		std::cout << "modified constract function!" << std::endl;
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	//String(const String& other) = delete;
	String(const String& other) :m_Size(other.m_Size) {
		m_Buffer = new char[strlen(other.m_Buffer) + 1];
		memcpy(m_Buffer, other.m_Buffer, strlen(other.m_Buffer) + 1);
	}

	char& operator[](int index) {
		return m_Buffer[index];
	}

	~String() {
		delete[] m_Buffer;
	}
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}

int main() {
	String test1("hello");
	String test2 = test1;

	test1[0] = 'A';

	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
}