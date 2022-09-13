#include<bits/stdc++.h>
using namespace std;

// Time complexity O(n)
// Space complexity of call stack O(n) while we are not using any extra
// stack O(1)
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}
void insertatBottom(stack<int> &s,int x){
    // base case
    if(s.empty()){
        s.push(x);
        return;
    }
    // rec case
    int data=s.top();
    s.pop();
    insertatBottom(s,x);
    s.push(data);

}
void reverse(stack<int> &s){
    // base case
    if(s.empty()){
        return;
    }
    // otherwise pop out the top element and and insert it at the bottom of 
    // 'reversed small stack'
    int x=s.top();
    s.pop();
    // rec reverse the smaller stack
    reverse(s);
    insertatBottom(s,x);
}
int main(){
    stack<int> s;
    for(int i=1;i<4;i++){
        s.push(i);
    }
    print(s);
    reverse(s);
    print(s);
    return 0;
}