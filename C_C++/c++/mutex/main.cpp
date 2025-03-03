#include <iostream>
#include <thread>
#include <mutex>

std::mutex carMutex;

void DriveCar(std::string driverName) {
	carMutex.lock();
	std::cout << driverName << " is driving\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << driverName << " is done driving\n";
	carMutex.unlock();
}

void DriveCar2(std::string driverName) {
	std::lock_guard<std::mutex> carLock(carMutex);
	std::cout << driverName << " is driving\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << driverName << " is done driving\n";
}

int main() {
	std::thread t1(DriveCar, "Jon");
	std::thread t2(DriveCar, "Steve");

	t1.join(); 
	t2.join();

	std::cin.get();
}