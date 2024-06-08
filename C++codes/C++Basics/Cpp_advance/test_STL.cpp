#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

void test_string(){
    char c[] = "jidwad达娃大达瓦达瓦达瓦";
    string cc;
    cc.assign(c, 8);
    cout << cc.at(4);
    cc.append("dawaw");
    cc.append(4, 'P');
    cout << cc.substr(2, 7) << endl;
    cout << cc << endl;
}
template<typename T>
void printVec(vector<T> v){
    for(auto it = v.begin();it != v.end();it++){
        cout << *it << " ";
    }
}
template<typename T>
void printDeq(deque<T> v){
    for(auto it = v.begin();it != v.end();it++){
        cout << *it << " ";
    }
}
void test_vector(){
    vector<char> v1;
    vector<double>  v2;
    v1.push_back('I');
    v1.push_back('O');
    v1.push_back('P');

    v2.push_back(0.4584);
    v2.push_back(0.458001);
    v2.push_back(0.4587455552001);
    
    
    v1.resize(8);
    v1.reserve(9);
    cout << endl << v1.size() << " " << v1.capacity() << endl;
    cout << endl << v2.size() << " " << v2.capacity() << endl;

    printVec<char>(v1);
    printVec<double>(v2);
    
}
void test_deque(){
    deque<int> dq;
    dq.push_back(4);
    dq.push_front(7);
     dq.push_back(41);
    dq.push_front(71);
     dq.push_back(54);
    dq.push_front(57);
    dq.insert(dq.begin() + 2, 101);
    printDeq(dq);
}
void test_list(){
    list<char> list(7, 'P');
    //list.remove('P');
    vector<char> v1;
    v1.push_back('I');
    v1.push_back('O');
    v1.push_back('P');
    v1.push_back('8');
    v1.push_back('R');
    
    list.insert(list.begin(), v1.begin(), v1.end());
   
    list.sort([=](int a, int b)-> bool { return a < b;});
    //cout << list.empty();
    for(auto it = list.begin();it != list.end();it++){
        cout << *it << " ";
    }
}
void test_set(){
    auto Print = [=](int a)-> void {cout << a << " ";};
    struct myRule
    {
        bool operator()(int a, int b){return a > b;}
    };
    
    multiset<int> mset;
    set<int, myRule> s;
    s.insert(7);s.insert(-8);s.insert(17);s.insert(10);
    for_each(s.begin(), s.end(), Print);
    //set 元素不重复
    mset.insert(17);
    mset.insert(7);
    pair<set<int, myRule>::iterator, bool> ret = s.insert(7);
    if(ret.second){cout << "suc";}
    else{cout << "fail";}

    set<int> ss;
    ss.insert(7);ss.insert(8);ss.insert(4);ss.insert(107);
    cout <<endl << ss.count(7) << endl;
    if(ss.find(100) == ss.end()) cout << "fail";
    else cout <<"suc";
   
}
void test_map(){
    map<int, char> mp;
    mp.insert(make_pair(7, 'E'));
    mp.insert(pair<int, char>(8, 'Q'));
    mp[9] = 'O';
    for(auto it = mp.begin();it!=mp.end();it++) 
        cout << it->first << " " << it->second << endl;
    map<int, char>::iterator it = mp.find(4);
    if(it ==mp.end()) cout << "failed" << endl;
    else cout << "success" << endl;
}
void test_hashmap(){
    unordered_map<char, int> hash;
    for (int i = 0; i < 5; i++)
    {
        /* code */
        hash.insert({'A' + i + 1, i * i});
    }
    for(auto i = hash.begin(); i != hash.end(); i++)
        cout << i->first <<" " << i->second << endl;
    
}

int main(){ 
    //test_string();
    //test_vector();
    //test_deque();
    //test_list();
    //test_set();
    //test_map();
    test_hashmap();
    return 0;
}