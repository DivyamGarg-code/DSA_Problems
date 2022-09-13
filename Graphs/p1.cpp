#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& v) {
    int k=0;
    int len=v.size();
    if(len==1){
        return;
    }
    for(int i=len-1;i>=1;i--){
        if(v[i]>v[i-1]){
            k=i;
            break;
        }
    }
    // cout<<k<<endl;
    int temp;
    for(int i=len-1;i>=k;i--){
        if(v[k-1]<v[i]){
            temp=i;
            break;
        }
    }
    // cout<<v[k-1]<<" "<<v[temp]<<endl;
    swap(v[k-1],v[temp]);
    if(k!=0 && (len-k)>1){
        reverse(v.begin()+k,v.end());
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    nextPermutation(v);
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}