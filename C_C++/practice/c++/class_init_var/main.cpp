#include <iostream>

class String {
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;		// input string safe
	}

	//String(const String& other):m_Buffer(other.m_Buffer), m_Size(other.m_Size){}
	//String(const String& other){memcpy(this, &other, sizeof(String));}
	String(const String& other) :m_Size(other.m_Size) { 
		std::cout << "copy!" << std::endl;
		m_Buffer = new char[m_Size + 1]; 
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	char& operator[](int num) { return m_Buffer[num]; }

	~String() { delete[] m_Buffer; }
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer;
	return stream;
}

void pointString(const String& string) {
	//string[1] = '1';
	std::cout << string << std::endl;
}

int main() {
	String string1 = "leos";
	String string2 = string1;

	string1[0] = 'A';

	std::cout << string1 << std::endl;
	std::cout << string2 << std::endl;

	std::cout << "**************************" << std::endl;

	pointString(string1);
	pointString(string2);
	return 0;
}



