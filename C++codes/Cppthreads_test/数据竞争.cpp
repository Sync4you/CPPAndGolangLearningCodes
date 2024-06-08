#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
int a = 0;
mutex t_mtx;
mutex m1, m2;
void add() {
	
	for (int i = 0; i < 10000; i++)
	{	
		t_mtx.lock();//»¥³âËø
		a++;
		t_mtx.unlock();
	}
}
void test1() {
	
	thread t1(add);
	thread t2(add);
	t1.join();
	t2.join();
	cout << a;
}
void fun1() {
	m1.lock();
	m2.lock();
	m1.unlock();
	m2.unlock();
}
void fun2() {
	m1.lock();
	m2.lock();
	m1.unlock();
	m2.unlock();
}
void test2() {
	thread t1(fun1);
	thread t2(fun2);
	t1.join();
	t2.join();
	cout << "endl" << endl;
}
