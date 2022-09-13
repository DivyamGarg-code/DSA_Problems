#include<bits/stdc++.h>
using namespace std;

int main(){
    // Problem - Unique numbers 2N+1
    // Given a list of no's where every no. occurs twice except one,find
    int n,x;
    cin>>n;
    int ans=0;
    for(int i = 0; i < n; i++){
        cin>>x;
        ans=ans^x;
    }
    cout<<ans;
    return 0;
}