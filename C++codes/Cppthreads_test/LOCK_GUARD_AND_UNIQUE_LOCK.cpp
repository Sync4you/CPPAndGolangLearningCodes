#include<iostream>
#include<thread>
#include<mutex>
std::timed_mutex tmtx;
int shared_data = 0;
void fun() {
	for (int i = 0; i < 2; i++) {
		std::unique_lock<std::timed_mutex> lg(tmtx, std::defer_lock);
		if (lg.try_lock_for(std::chrono::seconds(2)))
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			shared_data++;
		}
	}

}
//int main() {
//	std::thread t1(fun);
//	std::thread t2(fun);
//	t1.join();
//	t2.join();
//
//	std::cout << shared_data << std::endl;
//}