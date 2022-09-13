#include<bits/stdc++.h>
using namespace std;

// Maximum sum subarray of size k
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    int j=0;
    int sum=0;
    int ans=0;
    while(j<n){
        sum+=a[j];
        if(j-i+1<k){ // expand the window till its size becomes equal to k
            j++;
        }else if(j-i+1==k){
            ans=max(ans,sum);
            sum=sum-a[i];
            i++;
            j++;
        }
    }
    cout<<ans;
    return 0;
}