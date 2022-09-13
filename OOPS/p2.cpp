#include<bits/stdc++.h>
using namespace std;

void permute(char a[],int n,int i=0){
    if(i>=n){
        for(int k=0;k<n;k++){
            cout<<a[k]<<" ";   
        }
        cout<<endl;
        return;
    }
    for(int j=i;j<n;j++){
        swap(a[i],a[j]);
        permute(a,n,i+1);
        swap(a[i],a[j]); // backtrack
    }
}
int main(){
    int n;
    cin>>n;
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    permute(a,n);
}   