#include<bits/stdc++.h>
using namespace std;
/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
*/
// combinational sum: It is basically using the ame numbers again
// Time complexity exponential O(2^t*k)
// Space complexity 
void solve(int a[],int n,vector<int> temp,int target,int i=0){
    if(i>=n || target<0){
        return;
    }
    if(i<=n && target==0){
        for(auto x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    temp.push_back(a[i]);
    solve(a,n,temp,target-a[i],i);
    temp.pop_back();
    solve(a,n,temp,target,i+1);
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> temp;
    solve(a,n,temp,k);
    return 0;
}