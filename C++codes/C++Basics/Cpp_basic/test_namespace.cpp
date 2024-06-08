#include<iostream>

namespace NP1{
    int a = 10;
    void say(){
        std::cout<<a<<"endl";
    }
}

namespace NP2
{
    namespace NP3{
        int c = 8;

        void say(){std::cout<<c<<"endl";}
    }
    int a = 2;

    void say(){
        std::cout<<a<<"endl";
    }
} // namespace NP2
using namespace NP1;
using namespace NP2;

struct Test
{
    int a = 4;
    char num[];
    void show(){std::cout<<a<<" "<<"\n";}
};

int main(){
    std::cout<<NP1::a<<std::endl;
    NP1::say();
    NP2::say();
    NP3::say();
    Test t ;
    t.show();
}