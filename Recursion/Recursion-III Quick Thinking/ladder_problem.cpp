#include<bits/stdc++.h>
using namespace std;
// Ladder problem : can Jump 1,2,3,k steps find the number of ways to reach to the top N
int steps(int n,int k){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=0;
    for(int i = 1; i <=k; i++){
        ans+=steps(n-i,k);
    }
    return ans;
    
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<steps(n,k);
    return 0;
}