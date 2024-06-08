#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<functional>
#include<condition_variable>
#include<string>
#include<vector>
#include<queue>

class ThreadPool {
public:
	ThreadPool(int threadsNum) :stop(false){
		for (int i = 0; i < threadsNum; i++) {
			threads.emplace_back([this] {
				while (true) {
					std::unique_lock<std::mutex> lock(threadPoolMutex);
					threadPoolCV.wait(lock, [this] {
						return !tasks.empty() || stop;
						});

					if (stop && tasks.empty()) {
						return ;
					}

					std::function<void()> task(std::move(tasks.front()));
					tasks.pop();
					lock.unlock();
					task();
				}
				});
			
		}
	}
	~ThreadPool() {
		{
			stop = true;
			std::unique_lock<std::mutex> lock(threadPoolMutex);
		}

		threadPoolCV.notify_all();
		for (auto& t : threads) {
			t.join();
		}
	}
	template<class F, class...Args>
	void enqueue(F&& f, Args&&... args) {
		std::function<void()> task = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
		{
			std::unique_lock<std::mutex> lock(threadPoolMutex);
			tasks.emplace(std::move(task));
		}
		threadPoolCV.notify_one();
	}
private:
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::mutex threadPoolMutex;
	std::condition_variable threadPoolCV;
	bool stop;
};


//int main() {
//	ThreadPool pool(5);
//	for (int i = 0; i < 10; i++) {
//		pool.enqueue([i] {
//			std::cout << "task:" << i << "is running!" << std::endl;
//			std::this_thread::sleep_for(std::chrono::seconds(1));
//			std::cout << "task:" << i << "is done!" << std::endl;
//			});
//	}
//	return 0;
//}