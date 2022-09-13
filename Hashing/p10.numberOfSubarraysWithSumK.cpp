#include<bits/stdc++.h>
using namespace std;

int subarraySum(int a[], int n,int k) {
    unordered_map<int,int> m;
    int prefix=0;
    int ans=0;
    m[0]=1; // when the prefix==k
    for(int i=0;i<n;i++){
        prefix+=a[i];
        if(m.find(prefix-k)!=m.end()){
            ans+=m[prefix-k];
        }
        m[prefix]++;
    }
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<subarraySum(a,n,k);
    return 0;
}