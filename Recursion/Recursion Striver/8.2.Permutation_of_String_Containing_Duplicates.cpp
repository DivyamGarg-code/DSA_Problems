#include<bits/stdc++.h>
using namespace std;

void permute(int a[],int n,int &cnt,int j=0){
    if(j>=n){
        cnt+=1;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=j;i<n;i++){
        if(i>j && a[i]==a[i-1]){
            continue;
        }
        swap(a[i],a[j]);
        permute(a,n,cnt,j+1);
        swap(a[i],a[j]);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    permute(a,n,cnt);
    cout<<"cnt "<<cnt;
    return 0;
}