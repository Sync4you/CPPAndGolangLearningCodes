#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<chrono>
#include<memory>
using namespace std;
using fuck = int;//使用别名

class Cat{
    public:
        int age;
        Cat() = delete;
        Cat(const Cat& cat) = delete;
        Cat(int age):age(age){}
        void say(){cout << this->age << endl;}
};

void test_new_std(){
    //1--变量初始化支持大括号
    short quat[2]{20, 4};
    cout << quat[0] << endl;
    //2--stl容器支持初始化
    // vector<int> v1(5);
    // vector<char> v3(7, 'A');//7个A
    // vector<char> v2{'a', 'g', 'v'};
    // for(char c:v3)
    //     cout << c<< endl;

    //3--consexpr, 只读变量和常量语义分开
    //const int a = 14;
    constexpr char b = 'v';
    //int arr[a];
    cout << b << endl;
}
template<typename T>
void print(T && t)
{
    cout<<"rvalue"<<endl;
}
template<typename T>
void print(const T & t)
{
    cout<<"lvalue"<<endl;
}

template <typename T>
void test_forward(T && t)
{
    print(t);
    print(forward<T>(t));
    print(move(t));
}

void test_uniqptr(){
    unique_ptr<int> uniptr (new int(5));
    unique_ptr<int> uniptr2 = move(uniptr);
    uniptr2.reset(new int (7));
    cout << *uniptr2.get() << endl;
}
void test_sharedptr(){
    // shared_ptr<int> ptr1 (new int (7));
    // cout << "use:" << ptr1.use_count() << endl;
    // shared_ptr<int> ptr2(ptr1);
    // cout << "use:" << ptr2.use_count() << endl;
    // shared_ptr<int> ptr3 = move(ptr1);
    // cout << "use:" << ptr3.use_count() << endl;
    // cout << *ptr3.get();

    shared_ptr<char> ptr4 = make_shared<char>('A');
    shared_ptr<char> ptr5 = make_shared<char>('A');
    cout << ptr5.use_count() << " " << ptr4.use_count() << endl;
}
void test_weak_ptr(){
    shared_ptr<int> sp(new int);
    weak_ptr<int> wp1(sp);
    weak_ptr<int> wp2(wp1);
    weak_ptr<int> wp3(sp);
    weak_ptr<int> wp4, wp5;
    wp4 = sp;
    cout << "wp4:" << wp4.expired() << endl;
    //cout << wp1.use_count() << endl << wp2.use_count() << endl << wp3.use_count() << endl;
    //cout << wp4.use_count() << endl << wp5.use_count();

    sp.reset();
    cout << "wp1:" << wp1.expired() << endl;
    cout << "wp2:" << wp2.expired() << endl;

    shared_ptr<int> sp1,sp2;
    weak_ptr<int> wp;
    sp1 = make_shared<int> (100);
    wp = sp1;
    sp2 = wp.lock();
    cout << wp.use_count() << "wp-usecount" << endl;
    sp1.reset();
    cout << wp.use_count() << "wp-usecount" << endl;
    sp1 = wp.lock();
    cout << wp.use_count() << "wp-usecount" << endl;
    cout << *sp1 << " " << *sp2 << endl;
    
}
void test_chrono(){
    chrono::hours h1(1);
    chrono::minutes m1(60);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();

    if(h1 == m1)
        cout << "yes" << endl;
    chrono::steady_clock::time_point end =chrono::steady_clock::now();
    auto dt = end -  start;
    cout << dt.count() << "ns";

}
int main(void)
{
    //test_new_std();
    Cat c1(14), c2(11);
    //Cat c3;
    //Cat c3 = c2;
    //c3.say();
    //fuck a = 5;
    // cout << sizeof(fuck) << endl;
    // tuple<int, char, bool> mt{14, 'P', false};
    // cout << get<2>(mt);
    // auto [a, b, c] = mt;//解包
    // cout << b << endl;

    // string s1("dawd");
    // string s2(move(s1));
    // s1 = "fiad";
    // cout << s2<< endl << s1;
    // int i;
    // test_forward(i);
    // test_forward(4);


    //test_uniqptr();
    //test_sharedptr(); 
    //test_weak_ptr();
    test_chrono();
    return 0;
}
