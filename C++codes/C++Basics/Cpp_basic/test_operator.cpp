#include<iostream>
using namespace std;
class Maker{
    friend ostream& operator<<(ostream &out, Maker &m);
    friend istream& operator>>(istream& in, Maker &m);
    public:
        int a;
        int b;
        Maker(){}
        Maker(int a, int b){
            this->a = a;
            this->b = b;
        }
        Maker operator-(Maker &m){
            Maker tmp(this->a - m.a, this->b - m.b);
            return tmp;
        }
        bool operator==(Maker &m){
            if(m.a == this->a&&m.b == this->b)
                return true;
            return false;
        }
        Maker &operator++(){
            ++this->a;
            ++this->b;
            return *this;
        }
        Maker operator++(int){
            Maker tmp = *this;
            ++this->a;
            ++this->b;
            return tmp;
        }
        void operator()(int a, int b){
            //仿函数， 像函数一样的类
            /*
            --1 方便代码维护
            --2 作为算法策略
            --3 有权限的调用函数 
            */
            cout << a << " " << b << endl;
        }
        void say(){cout << a << " " << b << endl;}
};
Maker operator+(const Maker &m1, const Maker m2){
    Maker tmp(m1.a + m2.a, m1.b + m2.b);
    return tmp;
}
ostream& operator<<(ostream &out, Maker &m){
    out << m.a <<" " << m.b << endl;
    return out;
}
istream& operator>>(istream& in, Maker &m){
    in >> m .a >> m.b;
    return in;
}
int main(){
    Maker m1(1, 4);
    Maker m2(2, -2);
    Maker m4(1, 4);
   /*  if(m1 == m4){
        cout << "yes";
    } */
   /*  Maker m5 =  m4++;
    cout << m5 << endl;
    cout << m4 << endl;
    cout << ++m4 << endl;
    cout << m4 << endl; */

    //Maker m3 = m1 - m2;
    //m3.say();
    //cout << endl << m3;
   /*  cin >> m1;
    m1.say(); */

    Maker func;
    func(14, 77);
    return 0;

}