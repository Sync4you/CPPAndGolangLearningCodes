#include<iostream>
#include<thread>
#include<memory>
using namespace std;
//thread t;
//void foo(int &v) {
//	v++;
//}
//void test1() {
//	int a = 1;
//	t = thread(foo, ref(a));
//	
//}
class A {
	friend void thread_foo();
	private:
		int num = 0;
		void foo() {
			for (int i = 0; i < 10; i++)
			{
				this->num += 2;
				cout << this->num << endl;
			}
		}

};
void thread_foo() {
	shared_ptr<A> aa = make_shared<A>();//÷«ƒ‹÷∏’Î
	thread t(&A::foo, aa);
	t.join();
}
