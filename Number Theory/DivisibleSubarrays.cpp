#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int cumSum[n]={0}; // directly add the mod into that partiular index ie storing the frequencies
    cumSum[0]=1;
    int sum=0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum+=a[i];
        sum=sum%n;
        sum=(sum+n)%n;
        cumSum[sum]++;
    }
    int ans=0;
    for(int i = 0; i < n; i++){
        int m=cumSum[i];
        ans+=m*(m-1)/2;
    }
    cout<<ans;

    return 0;
}