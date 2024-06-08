#include<atomic>
#include<thread>
#include<mutex>
#include<iostream>
std::atomic<int> data = 0;
void fun_atomic() {
	for (int i = 0; i < 100000; i++)
	{
		data++;
	}
}

int main() {
	auto lst = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count();
	std::thread t3(fun_atomic);
	std::thread t4(fun_atomic);
	t3.join();
	t4.join();
	auto cur = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count();
	std::cout << "data:" << data << std::endl;
	std::cout << "time:" << cur - lst << std::endl;
	return 0;
}