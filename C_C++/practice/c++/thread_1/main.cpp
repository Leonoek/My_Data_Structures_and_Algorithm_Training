#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutex;
int global{ 0 };
class Test {
public:
	
	void point() {
		std::cout << "hello" << std::endl;
	}

	void add() {
		for (size_t i = 0; i < 10000; i++)
		{
			//mutex.lock();
			global++;
			//mutex.unlock();
		}
	}
};

int main() {
	Test test;
	std::thread thread1(&Test::add, test);
	std::thread thread2(&Test::add, test);
	if (thread1.joinable())	thread1.join();
	else std::cout << "could not using join method of thread!\r\n";

	if (thread2.joinable())	thread2.join();
	else std::cout << "could not using join method of thread!\r\n";

	std::cout << global << std::endl;

	return 0;
}