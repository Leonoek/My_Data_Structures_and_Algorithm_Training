#include <iostream>

class String {
public:
	String() = default;
	String(const char* string) {
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);		// dirty Data pollution!
	}

	String(const String& other) {
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);	// assume input data is clean!
	}

	String(String&& other) noexcept {
		printf("Moved!\r\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	String& operator=(String&& other) noexcept {
		printf("Moved!\n");

		if (this != &other)
		{
			//delete[] m_Data;

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
		}
		
		return *this;
	}

	~String() {
		printf("Destoryed!\n");
		delete m_Data;
	}

	void Print() {
		for (size_t i = 0; i < m_Size; i++)
		{
			printf("%c", m_Data[i]);
		}
		printf("\n");
	}
private:
	char* m_Data;
	uint32_t m_Size;
};

class Entity {
public:
	Entity(const String& name) :m_Name(name) {}

	Entity(String&& name):m_Name(std::move(name)){}

	void PrintName() { m_Name.Print(); }
private:
	String m_Name;
};

int main() {
	String string1("Mew");

	Entity entity("Cherno");
	entity.PrintName();

	String string = "Hello";
	//string.Print();
	String dest = std::move(string);

	dest = std::move(string1);

	std::cin.get();
}