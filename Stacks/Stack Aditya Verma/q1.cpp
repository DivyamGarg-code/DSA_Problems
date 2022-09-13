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
    stack<pair<int,int>> s; // pair(stock price,index)
    vector<int> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        while(!s.empty()){
            if(a[i]<=s.top().first){
                v.push_back(i-s.top().second);
                break;
            }else{
                s.pop();
            }
        }
        if(s.empty()){
            v.push_back(i+1);
        }
        s.push({a[i],i});
    }
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}