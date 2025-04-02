#include <iostream>
#include <thread>

bool finished = false;

void DoWork() {
	std::cout << "started thread id=" << std::this_thread::get_id() << std::endl;
	using namespace std::literals::chrono_literals;
	while (!finished) {
		std::cout << "Working...\n";
		std::this_thread::sleep_for(1s);
	}
}

int main() {
	std::cout << "main thread id=" << std::this_thread::get_id() << std::endl;
	std::thread worker(DoWork);

	std::cin.get();
	finished = true;

	worker.join();
	std::cout << "main thread id=" << std::this_thread::get_id() << std::endl;

	std::cin.get();
}