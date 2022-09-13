#include<bits/stdc++.h>
using namespace std;

// K_th Premutation from all the permutations in the sorted order
/*
 1. 123
 2. 132
 3. 213
 4. 231
 5. 312
 6. 321
*/ 
// Time Complexity O(n^2)
// Space Complexity O(n)
void print(string &s,string &ans,vector<int> &v,int k,int i){
    if(i==0){
        ans.push_back(s[0]);
        for(auto x:ans){
            cout<<x<<" ";
        }
        return;
    }
    int idx=(k/v[i-1]);
    idx=idx%(i+1);
    ans.push_back(s[idx]);
    s.erase(s.begin()+idx); // Important step to get the permutation in order
    print(s,ans,v,k,i-1);
}

string getPermutation(int n, int k) {
    string s;
    string ans;
    for(int i=1;i<=n;i++){
        s.push_back(char(i+'0'));
    }

    vector<int> v(n,0);
    v[0]=1;
    for(int i=1;i<n;i++){
        v[i]=(i+1)*v[i-1];
    }
    print(s,ans,v,k-1,n-1);    
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    getPermutation(n,k); 
    return 0;
}