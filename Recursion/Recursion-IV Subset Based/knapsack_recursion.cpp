#include<bits/stdc++.h>
using namespace std;
int profit(int N,int C,int wt[],int prices[]){
    if(N==0 || C==0){
        return 0;
    }
    int ans=0;
    int inc,exc;
    inc=exc=0;
    // include
    if(wt[N-1]<=C){
        inc=prices[N-1]+profit(N-1,C-wt[N-1],wt,prices);
    }
    //exclude
    exc=profit(N-1,C,wt,prices);
    ans=max(inc,exc);
    return ans;
}

int main(){
    int n, w;
    cin>>n>>w;
    
    int val[n];
    int wt[n];
    
    //inserting the values
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    //inserting the weights
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<profit(n,w,wt,val);
    return 0;
}