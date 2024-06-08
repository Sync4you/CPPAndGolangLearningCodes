#include<iostream>
#include<thread>
#include<string>
#include<mutex>
static std::once_flag once;
class Log {
private:

		Log(){}
		Log(const Log& log) = delete;
		Log& operator=(const Log& log) = delete;
	
public:
	static Log* log;
	static Log& GetOneInstance() {
		//static Log log;//饿汉模式
		//return log;

		//static Log* log = nullptr;
		//if (!log) {
		//	log = new Log();
		//}
		//return *log; //懒汉模式

		std::call_once(once, init);
		return *log;
	}
	void printLog(std::string msg) {
		std::cout << __TIME__ << msg << std::endl;
	}
	static void init() {
		if (!log) {
			log = new Log;
		}
	}
};
Log* Log::log = nullptr;
void printErr() {
	Log::GetOneInstance().printLog("error");
}
//int main() {
//	std::thread t1(printErr);
//	std::thread t2(printErr);
//	t1.join();
//	t2.join();
//	return 0;
//
//}