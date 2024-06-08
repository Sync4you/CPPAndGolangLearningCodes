#include<functional>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void test1(){
    plus<int> mp;
    multiplies<int> mul;
    vector<int> v;
    for(int i =0; i< 7; i++) v.push_back(i * i - 5 * i + 1);
    cout << mp(4, 5) <<" " << mul(7, 10) << " " << endl;
    sort(v.begin(), v.end(), less<int>());
    //for(int i =0; i< 7; i++) cout << v[i] << " ";
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    vector<bool> v1;
    v1.push_back(false);
    v1.push_back(true);v1.push_back(false);
    v1.push_back(true);v1.push_back(true);
    vector<bool> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    for_each(v2.begin(), v2.end(), [](bool b){cout << b << " ";});
}

struct Myfunc: public binary_function<int, int, void>
{
    void operator()(int v1, int v2) const{
            cout << v1 + v2 << " ";
    }
};
struct Myfind:public unary_function<int, bool>{
    bool operator()(int v) const{
        return v == 5;
    }
};
void test2(){
    //适配器
    vector<int> v;
    for(int i =0; i< 7; i++) v.push_back(5);
    //for_each(v.begin(), v.end(), bind2nd(Myfunc(), 10));
    //bind1st 将参数给第一个，bind2nd将参数给第二个
    //not1, not2 取反
    vector<int>::iterator ret = find_if(v.begin(), v.end(), not1(Myfind()));
    if(ret == v.end()) cout <<" fail" << endl;
    else cout << "succ" << endl;
    for_each(v.begin(), v.end(), [](int v){cout << v << " ";});

}
void print(int v){cout <<v << " ";}
class Maker{
    public:
        string name;
        int age;
        Maker(string name, int age){
            this->name = name;
            this->age = age;
        }
        void printMaker(){
    cout << this->name <<  " " << this->age << " " << endl;
}
};

void test3(){
    vector<int> v;
    for(int i =0; i< 7; i++) v.push_back(i);
    //ptr_fun 普通函数适配
    for_each(v.begin(), v.end(), ptr_fun(print));
    vector<Maker> vm;
    vm.push_back(Maker("ada", 14));
    vm.push_back(Maker("wda", 17));
    vm.push_back(Maker("plp", 10));
    for_each(vm.begin(), vm.end(), mem_fun_ref(Maker::printMaker));

}
int main(){
    //test1();
    //test2();
    test3();
}