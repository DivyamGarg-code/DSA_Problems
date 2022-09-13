#include<bits/stdc++.h>
using namespace std;

/*
Print all Permutations of a String/Array | Recursion | Approach 
TIME COMPLEXITY O(N!*N) as you are running loop n times
Auxiliary space o(n)
Not using any extra space 

*/
void permute(vector<int> &v,int n,vector<vector<int>> ans,int j=0){
    if(j>=n){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
        ans.push_back(v);
        return;
    }
    for(int i=j;i<n;i++){
        swap(v[i],v[j]);
        // temp.push_back(v[i]);
        permute(v,n,ans,j+1);
        swap(v[i],v[j]);// backtracking
        // temp.pop_back();
    }
}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<vector<int>> ans;
    permute(v,n,ans);
    return 0;
}


