#include<bits/stdc++.h>
using namespace std;
void f2(int a,int &b){
    b=a*2;
    return;
}
int f1(int a){
    int b=0;
    f2(a,b);
    return b;
}
int main(){
    int a;
    cin>>a;
    cout<<f1(a);
    return 0;
}