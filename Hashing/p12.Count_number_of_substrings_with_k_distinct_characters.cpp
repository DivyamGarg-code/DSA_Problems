#include<bits/stdc++.h>
using namespace std;

// OPTIMISED SOLUTION
// TC O(n)
// SC O(n) in case of map and O(1) in case of array

// Count number of substrings having at most K distinct characters
int atmostKdistinctCharacters(vector<int> s,int k){
    int sl=s.size();
    unordered_map<char,int> mp;
    int ans=0;
    int i=0;
    int j=0;
    int window_size=0;
    int max_size=0;
    while(j<sl){
        mp[s[j]]++;
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        ans+=j-i+1;
        j++;
    }
    return ans;
}

// FOR GETTING COUNT OF SUBSTRINGS HAVING K DISTINCT CHARACTERS
// SUBBTRACT atmostKdistinctCharacters(K)-atmostKdistinctCharacters(K-1)

int main(){
    vector<int> s;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push_back(x);
    }
    cout<<atmostKdistinctCharacters(s,k)-atmostKdistinctCharacters(s,k-1);
    return 0;
}