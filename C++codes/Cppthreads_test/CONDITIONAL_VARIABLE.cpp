#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<queue>
#include<condition_variable>
std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex mtx;
void producer() {
	for (int i = 0; i < 8; ++i) {
		{
			std::unique_lock<std::mutex> lock(mtx);
			g_queue.push(i + 1);
			g_cv.notify_one();
			std::cout << "Producer:" << i + 1 << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
void consumer() {
	while (true) {
		std::unique_lock<std::mutex> lock(mtx);
		g_cv.wait(lock, []() {return !g_queue.empty(); });
		int v = g_queue.front();
		g_queue.pop();
		std::cout << "Comsumer:" << v << std::endl;
	}
}
//int main() {
//	std::thread t1(producer);
//	std::thread t2(consumer);
//	t1.join();
//	t2.join();
//	return 0;
//}
