#include<bits/stdc++.h>
using namespace std;

// Longest Consecutive Sequence 1
// using sorting 
// TC O(nlogn)
// SC O(1)

int longestConsecutive(vector<int> &v) {
    int n=v.size();
    if(n==0){
        return 0;
    }
    sort(v.begin(),v.end());
    int pre=v[0];
    int cnt=1;
    int len=1;
    for(int i=1;i<n;i++){
        if(pre==v[i]){
            continue;
        }else if(pre+1==v[i]){
            cnt++;
            pre=v[i];
            len=max(len,cnt);
        }else{
            cnt=1;
            pre=v[i];
            len=max(len,cnt);
        }
    }
    return len;
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
    cout<<longestConsecutive(v);
    return 0;
}