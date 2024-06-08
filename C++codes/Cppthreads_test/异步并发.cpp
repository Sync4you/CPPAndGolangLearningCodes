#include<iostream>
#include<future>

int fun() {
	int j = 0;
	for (int i = 0; i < 1000; i++) {
		j = i;
	}
	return j;
}
void func(std::promise<int> &f) {
	f.set_value(7);
}
//int main() {
//	/*std::future<int> future_res = std::async(std::launch::async, fun);
//	
//	std::packaged_task<int()> task(fun);
//	auto res = task.get_future();
//	std::thread t(std::move(task));
//	std::cout << fun() << std::endl; 
//	t.join();
//	std::cout << res.get() << std::endl;*/
//	/*std::cout << future_res.get() << std::endl;*/
//
//	std::promise<int> f;
//	auto res = f.get_future();
//	std::thread tt(func, std::ref(f));
//	
//	tt.join();
//	std::cout << res.get() << std::endl;
//	return 0;
//}