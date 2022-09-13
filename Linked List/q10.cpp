#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    int *p=&a;
    cout<<a<<endl;
    cout<<p<<endl;
    delete p;
    cout<<&a<<endl;
    cout<<p<<endl;
}