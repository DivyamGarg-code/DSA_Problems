#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long int a[],long long int n,long long int m,long long int mid){
    long long int sum=0;
    for(int i = 0; i < n; i++){
        if(mid<a[i]){
            sum+=a[i]-mid;
        }
    }
    if(sum>=m){
        return true;
    }
    return false;
}
int main(){
    
    long long int n,m; // n-> number of woods  m-> cutting atleast this much wood
    cin>>n;
    cin>>m;
    long long int a[n]; // height of n trees
    for(long long int i = 0; i<n; i++){
        cin>>a[i];
    }
    long long int max_element=a[0];
    for(int i = 1; i < n; i++){
        max_element=max(max_element,a[i]);
    }
    long long int start=0;
    long long int end=max_element;
    long long int ans=0;
    while(start<=end){
        long long int mid=start+(end-start)/2;
        if(isPossible(a,n,m,mid)==true){
            ans=mid;
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}