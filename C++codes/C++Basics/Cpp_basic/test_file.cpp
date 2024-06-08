#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void test1(){
    //char c = cin.get();
    char c = cin.peek();
    char d = cin.get();   
    cout << c <<endl << d << endl;
}
void test2(){
    string s;
    char buf[1024] ={0};
    cin.getline(buf, 512);
    cout << buf;
}
void test3(){
    char buf[] = "hello fuck";
    cout.width(40);
    cout.fill('*');
    cout.setf(ios::right);
    cout.unsetf(ios::dec);
    cout.write(buf, 10);
    cout.setf(ios::hex);
    cout.setf(ios::showbase);
    cout << setiosflags(ios::fixed);
    cout << setprecision(4);
    cout << 87.154848 << endl;
}
void test4(){
    ofstream ofs;
    ofs.open("data.txt", ios::out | ios::trunc);
    if(!ofs.is_open()){
        cout << "open file failed" << endl;
    }
    ofs << "dawjdiadaw" << endl;
    ofs << "pppp" << endl;
    ofs.close();
}
void test5(){
    ifstream ifs ;
    ifs.open("data.txt", ios::in);
    if(!ifs.is_open()){
        cout << "fail";
    }
    //读取文件
    //一行行的
    
    /* char buf[1024] = {0};
    while ((ifs >> buf))
    {
        cout << buf << endl;

    }
    ifs.close(); */

    //第二种
    /* char buf[1024] = {0};
    while(!ifs.eof()){
        ifs.getline(buf, sizeof(buf));
        cout << buf << endl;
    } */

    //第三种，字符读取
    /* char c;
    while((c=ifs.get())!=EOF){
        cout << c;
    }
    ifs.close(); */

    

    
}
int main(void){
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}