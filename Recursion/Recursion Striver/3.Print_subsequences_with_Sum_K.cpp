#include<bits/stdc++.h>
using namespace std;

// Print subsequences with the sum k
void solve(int a[],int n,int k,vector<int> temp,vector<vector<int>> &v,int i=0,int sum=0){
    if(i>=n){
        if(sum==k){
            for(auto x:temp){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        // cout<<"Sum : "<<sum<<endl;
        return;
    }
    temp.push_back(a[i]);
    sum+=a[i];
    solve(a,n,k,temp,v,i+1,sum);
    sum-=a[i];
    temp.pop_back();
    solve(a,n,k,temp,v,i+1,sum);
}
void printSubsequences(int a[],int n,int k){
    vector<vector<int>> v;
    vector<int> temp;
    solve(a,n,k,temp,v);
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printSubsequences(a,n,k);
    return 0;
}