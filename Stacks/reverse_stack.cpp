#include<bits/stdc++.h>
using namespace std;

// Reversing stack using 1  other stack
// TC O(n^2)
// SC O(n)
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> s1;
    stack<int> s2;
    for(int i=4;i>=1;i--){
        s1.push(i);
    }
    print(s1);
    cout<<endl;
    int n=s1.size();
    for(int i=1;i<n;i++){
        int x=s1.top();
        s1.pop(); // poped the topmost element
        int k=n-i;
        while(k>0){  // shifting the remaining elements to s2
            s2.push(s1.top());
            s1.pop();
            k--;
        }
        s1.push(x); // pushing the element x to bottom of s1
        while(!s2.empty()){ // shifting elements back to s1
            s1.push(s2.top());
            s2.pop();
        }
    }
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return 0;
}

/* Reversing stack using 2 stacks TC-O(n) SC O(n)*/