#include<iostream>
class MyClass {
private:
    int x;
public:
    int createNewObject();
};
class iClass : public MyClass
{

};
int MyClass::createNewObject() {
    iClass* newObj = new iClass();

    newObj->x = 10; // 可以访问私有成员x
    return *(int *)(void *)newObj;
}
int main(){
    MyClass my ;
    int res = my.createNewObject();
    //std::cout << res;
    std::cout << *(int*)(void *)(&my) - res << std::endl << sizeof(iClass) ;
    return 0;
}