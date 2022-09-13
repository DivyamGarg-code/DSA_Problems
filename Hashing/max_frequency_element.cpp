#include<bits/stdc++.h>
using namespace std;

// Maximum Frequency Element
/*
TIME COMPLEXITY O(N)
Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.
*/

int main(){

    unordered_map<int,pair<int,int>> m; // pair(freq,indx)
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<v.size();i++){
        if(m.count(v[i])==0){
            m[v[i]].second=i;
        }
        m[v[i]].first+=1;
    }

    int ans;
    int maxi=INT_MIN;
    int min_idx;
    for(auto x:m){
        int value=x.first;
        int freq=x.second.first;
        int idx=x.second.second;
        if(freq>maxi){
            ans=value;
            maxi=freq;
            min_idx=idx;
        }else if(freq==maxi){
            if(idx<min_idx){
                ans=value;
                maxi=freq;
                min_idx=idx;
            }
        }
    }
    cout<<ans;


    return 0;
}