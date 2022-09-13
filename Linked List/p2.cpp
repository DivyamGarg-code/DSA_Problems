#include <bits/stdc++.h>
using namespace std;
void print(int* &b){
    int* c=new int(10);
    cout<<"adress of c "<<c<<endl;
    cout<<"adress of a stored in b "<<b<<endl;;
    b=c;
    // int** d=&b;
    // cout<<d<<endl; // d gives the variable adress of b
    // *d=c;
}
int main(){
    int a=10;
    int* b=&a;
    cout<<a<<endl;
    cout<<"adress of a stored in b "<<b<<endl;
    cout<<"adress of b "<<&b<<endl;
    print(b);
     cout<<"adress of c stored in b "<<b<<endl;
}