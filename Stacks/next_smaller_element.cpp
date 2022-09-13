#include<bits/stdc++.h>
using namespace std;

// Next Smaller Element
// Approach 1 TC O(n^2) applying 2 loops
// Approach 2 TC : O(n)  using stack
int main(){
    vector<int> v;
    stack<int> s;
    stack<int> s1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && (v[i]<s.top() || v[i]==s.top())){
            s.pop();
        }
        if(s.empty()){
            s1.push(-1);
        }else{
            s1.push(s.top());
            
        }
        s.push(v[i]);
    }
    while(!s1.empty()){
        cout<<s1.top()<<" ";
        s1.pop();
    }
    return 0;
}