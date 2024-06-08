#include<iostream>
using namespace std;
template<typename T>
void func(T a, T b){
    cout << a + b * b << endl;
    cout << "����ģ��" << endl;
}
//������ʱ�����һ�Σ������滻���ٱ���һ��
void func(int a, int b){
    cout << a + b * b << endl;
    cout << "��ͨ����" << endl;
}
template<class T1, class T2>
class Person{
    public:
        T1 name;
        T2 age;
        Person(T1 n, T2 a){
            name = n;
            age = a;
        }
        void say(){cout << name << " " << age << endl;}
};
template<class T = char>
class AA{
    public:
        T sex = 'C';
        void show(T a);
};
template<class T>
void AA<T>::show(T a){
    this->sex = a;
    cout << a;
}

class A:public AA<int>{
    public:
        void show(int a);
};
void A::show(int a){
    cout << this->sex << endl;
    this->sex = a;
    cout << a;
}
template<class T>
class C{
    public:
        T a;
        C(T aa):a(aa){}
        template<typename U>
        friend void show(const C<U> &cc);

};
template<typename U>
void show(C<U> &cc){
    cout << cc.a << endl;
}
int main(void){
    /* func<int>(14, 2.1);//����ʽת��
    func(14, 1.1);//��ͨ����
    func(2, 11);//������ͨ����
    func<>(1, 1);//<>�ղ��б�ǿ��ʹ�ú���ģ��
    Person<string, int> p("LI", 18);
    p.say(); */

    /* AA<> a;
    a.show('p');
    A aa;
    aa.show(7); */

    C<double> cc(2.012408f);
    show(cc);
    return 0;
}