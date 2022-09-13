#include<bits/stdc++.h>
using namespace std;

/*
Find the absolute difference between maximum and minimum frequency lying in the given range 
Time Complexity Using Brute Force : O(N+26)*Q

But By using Fenwik Tree Time complexity reduces to 
Time Complexity: O(|Q| * log(N) * 26)
Auxiliary Space: O(N * 26)
*/
void maxDiffFreq(char *ch,vector<pair<int,int>> &q){
    for(auto x:q){
        int freq[26]={0};
        int l=x.first-1;
        int r=x.second-1;
        for(int i=l;i<=r;i++){
            freq[ch[i]-'a']++;
        }
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                maxi=max(maxi,freq[i]);
                mini=min(mini,freq[i]);
            }
        }
        cout<<(maxi-mini)<<endl;
    }
}
int main(){
    int n,queries;
    cin>>n>>queries;
    char ch[n];
    for(int i=0;i<n;i++){
        cin>>ch[i];
    }
    vector<pair<int,int>> q;
    q.reserve(queries);
    for(int i=0;i<queries;i++){
        int l,r;
        cin>>l>>r;
        q.push_back({l,r});
    }
    maxDiffFreq(ch,q);
    return 0;
}