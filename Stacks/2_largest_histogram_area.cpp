#include<bits/stdc++.h>
using namespace std;
// Largest Histogram Area
// Time complexity O(n)
// Space complexity O(n)
int* left(vector<int> v,int n){
    stack<pair<int,int>> s;
    int* l_idx=new int[n];
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
    return l_idx;
}

int* right(vector<int> v,int n){
    stack<pair<int,int>> s;
    int* r_idx=new int[n];
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && (v[i]<s.top().first || v[i]==s.top().first)){
            s.pop();
        }
        if(s.empty()){
            r_idx[i]=-1;
        }else{
            r_idx[i]=s.top().second;
            
        }
        s.push(make_pair(v[i],i));
    }
    return r_idx;
}

int main(){
    vector<int> v;
    int area=INT_MIN;
    int n,ans,r_ans,l_ans;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int* l=left(v,n); // array of indices for prev smaller element
    int* r=right(v,n); // // array of indices for next smaller element
    for(int i=0;i<n;i++){
        l_ans=0;
        r_ans=0;
        if(l[i]==-1){
            l_ans=i*v[i];
        }else{
            l_ans=(i-l[i]-1)*v[i];
        }
        if(r[i]==-1){
            r_ans=(n-i-1)*v[i];
        }else{
            r_ans=(r[i]-i-1)*v[i];
        }
        ans=l_ans+r_ans+v[i];
        area=max(area,ans);
    }

    return 0;
}