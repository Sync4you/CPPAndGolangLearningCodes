#include<iostream>
#include<string>
using namespace std;
class Building;//需要先声明一下
class Friend2{
    public:
        void func1(Building& bd);
};
class Building{
    friend class Friend; //声明友元类
    friend void visiting(Building &bd);//声明全局函数为build的友元函数
    friend void Friend2::func1(Building &bd);//声明类的成员函数为友元
    //不是成员函数
    public:
        string livingroom;
        Building(){
            this->bedroom = "fucking bed";
            this->livingroom = "fucking sofa";
        }
        Building(string b, string l){
            this->bedroom = b;
            this->livingroom = l;
        }
    private:
        string bedroom;

};
class Friend{
    public:
        void visiting(Building &bd){
            cout << "visiting: " << bd.livingroom << endl;
            cout << "visiting: " << bd.bedroom << endl;
        }
        void func(){
            cout << "visiting: " << this->bd->livingroom << endl;
            cout << "visiting: " << this->bd->bedroom << endl;
        }
       
        Friend(){
            bd = new Building;
        }
        Friend(const Building& bd){
            this->bd = new Building(bd);
        }
        ~Friend(){
            if(bd != NULL){
                delete bd;
            }
        }
    public:
        Building *bd;//buiding类的指针
};
void visiting(Building &bd){
    cout << "visiting: " << bd.livingroom << endl;
    cout << "visiting: " << bd.bedroom << endl;
}
void Friend2::func1(Building &bd){
    cout << "visiting: " << bd.livingroom << endl;
    cout << "visiting: " << bd.bedroom << endl;
}
void testFriendFunc(){
    Building bd;
    visiting(bd);
}
void testFriendClass(){
    Building bd;
    Friend fd;
    fd.visiting(bd);
}
void testFriendClassPro(){
    Building bd("playing place", "drinking caffee");
    Friend fd1;
    fd1.func();
    Friend fd2(bd);//拷贝构造
    fd2.func();
}
void testFriendClassFunc(){
    Building bd("sleep", "fuck");
    Friend2 fd2;
    fd2.func1(bd);
}
int main(){
    /*
    友元是单向的
    无法被继承
    且不具有传递性
    friend关键字出现在声明处
    友元类没有this指针
    任意属性都可以被友元函数访问
    */
    //testFriendFunc();
    //testFriendClass();
    //testFriendClassPro();
    testFriendClassFunc();
    return 0;
}