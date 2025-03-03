#include <iostream>

class String {
public:
	String() = default;
	//String(const char* string) {
	//	std::cout << "Create!" << std::endl;
	//	m_Size = strlen(string);
	//	m_Data = new char[m_Size + 1];
	//	memcpy(m_Data, string, m_Size);
	//	m_Data[m_Size] = 0;
	//}

	String(const char* string) {
		std::cout << "Create!" << std::endl;
		m_Size = strlen(string);
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, string, m_Size + 1);
	}

	String(const String& other) {
		std::cout << "Copied!" << std::endl;
		m_Size = other.m_Size;
		m_Data = new char[m_Size + 1];
		memcpy(m_Data, other.m_Data, m_Size + 1);
	}

	String(String&& other) noexcept {
		//std::cout << "Moved!" << std::endl;
		//m_Size = other.m_Size;
		//m_Data = new char[m_Size + 1];
		//memcpy(m_Data, other.m_Data, m_Size + 1);

		std::cout << "Moved!" << std::endl;
		m_Size = other.m_Size;
		m_Data = other.m_Data;
		
		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~String() {
		delete m_Data;
	}
private:
	char* m_Data;
	size_t m_Size;
};

class Entity {
public:
	Entity(const String& name) :m_Name(name) {

	}

	Entity(String&& name) :m_Name(std::move(name)) {

	}
private:
	String m_Name;
};

int main() {
	String string("haha");
	Entity entity(std::move(string));
	return 0;
}