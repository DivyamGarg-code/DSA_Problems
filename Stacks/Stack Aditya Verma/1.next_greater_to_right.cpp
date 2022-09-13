#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    stack<int> s;
    vector<int> v;
    v.reserve(n);
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            v.push_back(-1);
        }else{
            while(!s.empty()){
                if(s.top()>a[i]){
                    v.push_back(s.top());
                    break;
                }else{
                    s.pop();
                }
            }
            if(s.empty()){
                v.push_back(-1);
            }
        }
        s.push(a[i]);
    }
    reverse(v.begin(),v.end());
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}