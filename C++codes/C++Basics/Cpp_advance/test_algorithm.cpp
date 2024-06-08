#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
void test_search(){
 /*    vector<int> v1;
    for(int i=0;i<7;i++) v1.push_back(i * i - 2 * i + 1);
    vector<int>::iterator ret1 = find(v1.begin(),v1.end(), -2);
    if(ret1==v1.end()) cout << "search failed" << endl;
    else cout << "search succeed" << endl;

    vector<int>::iterator ret2 = find_if(v1.begin(),v1.end(),[](int v){return v == 4;});
    if(ret2==v1.end()) cout << "search failed" << endl;
    else cout << "search succeed" << endl; */

    vector<int> v2;v2.push_back(8);
    for(int i=0;i<2;i++) v2.push_back(7);
    v2.push_back(1);v2.push_back(8);

    vector<int>::iterator ret3 = adjacent_find(v2.begin(), v2.end());
    cout << *ret3;

    vector<int> v3;
    for(int i=0;i<10;i++) v3.push_back(i *5 - 10);
    bool b = binary_search(v3.begin(), v3.end(), 20);
    cout << b;
    
}
void test_sort(){
    vector<int> v1, v2, v3;
    for(int i=0;i<6;i++) {
        v1.push_back(i *5 - i * i + 5);
        v2.push_back(i * 4 - 5);
     }
    v3.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    //for_each(v3.begin(), v3.end(), [](int v){cout << v << " ";});
    random_shuffle(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](int v){cout << v << " ";});
}
void test_others(){
    vector<int> v1, v2, v3;
    for(int i=0;i<6;i++) {
        v1.push_back(i * 3 - i * i + 5);
        v2.push_back(i * 2 - 5);
    }
    /*for_each(v1.begin(), v1.end(), [](int v){cout << v << " ";});
     replace(v1.begin(), v1.end(),1, 4);
    for_each(v1.begin(), v1.end(), [](int v){cout << v << " ";}); */

   /*  for_each(v2.begin(), v2.end(), [](int v){cout << v << " ";});
    replace_if(v2.begin(), v2.end(), [](int v){return v <=0;}, -77);
    for_each(v2.begin(), v2.end(), [](int v){cout << v << " ";}); */
    v3.resize(5);
    fill(v3.begin(), v3.end(), 3);
    int sum = accumulate(v3.begin(), v3.end(), 1);
    cout << sum;
    swap(v1, v3);
    for_each(v1.begin(), v1.end(), [](int v){cout << v << " ";}); 
}
int main(){
    //test_search();
    //test_sort();
    test_others();
}