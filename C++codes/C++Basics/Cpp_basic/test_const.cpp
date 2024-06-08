#include<iostream>
using namespace std;
const int a = 89;
void test(){
    const int b =14;
    int* p = (int *)&b;
    *p = 7;
    cout<<a<<endl;
    cout<<*p<<endl;
    cout<<&b<<endl;
    cout<<p<<endl; 
}

int main()
{
    test();
    return 0;
}
