#include<bits/stdc++.h>
using namespace std;

// Prev Smaller Element
// Approach 1 TC O(n^2) applying 2 loops
// Approach 2 TC : O(n)  using stack
int main(){
    vector<int> v;
    stack<pair<int,int>> s;
    int n;
    cin>>n;
    int* l_idx=new int[n];
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        while(!s.empty() && (v[i]<s.top().first || v[i]==s.top().first)){
            s.pop();
        }
        if(s.empty()){
            l_idx[i]=-1;
        }else{
            l_idx[i]=s.top().second;
            
        }
        s.push(make_pair(v[i],i));
    }
    for(int i=0;i<n;i++){
        cout<<l_idx[i]<<" ";
    }
    return 0;
}