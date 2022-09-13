#include<bits/stdc++.h>
using namespace std;


int max_sum(vector<vector<int>> &t,vector<vector<int>> &v,int n,int i=0,int j=-1){
    if(i==n){
        return 0;
    }
    if(j>=0 && t[i][j]!=-1){
        return t[i][j];
    }
    int maxi=INT_MIN;
    for(int k=0;k<3;k++){ // traversing from left to right
        if(k!=j){
            int x=v[i][k]+max_sum(t,v,n,i+1,k);
            maxi=max(maxi,x);
        }
    }
    return t[i][j]=maxi;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> t(n,vector<int>(3,-1));
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<3;j++){
                int x;
                cin>>x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        cout<<max_sum(t,v,n)<<endl;
    }
    return 0;
}