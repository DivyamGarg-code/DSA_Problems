#include<bits/stdc++.h>
using namespace std;

int solve(int a[],int n,int k,int i=0,int sum=0){
    if(i>=n){
        if(sum==k){
            return 1;
            // for(auto x:temp){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
        }
        // cout<<"Sum : "<<sum<<endl;
        return 0;
    }
    sum+=a[i];
    int l=solve(a,n,k,i+1,sum);
    sum-=a[i];
    int r=solve(a,n,k,i+1,sum);
    return l+r;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,n,k);
    return 0;
}