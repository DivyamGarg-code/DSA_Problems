#include<bits/stdc++.h>
using namespace std;

// length of longest subarray with sum=k
// TC=O(N)
// SC=O(N)

int longestSubarraywithSum_K(vector<int>&a, int n,int k){   
    unordered_map<int,int> m; // unordered_map<prefix_sum,first_index>
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++){
        pre+=a[i];
        if(m.count(pre)==0){
            if(pre==k){
                m[pre]=i;
                len=max(len,i+1);
            }else{
                m[pre]=i;
                if(m.count(pre-k)!=0){
                    len=max(len,i-m[pre-k]);
                }
            }
        }else{ 
            if(m.count(pre-k)!=0){
                len=max(len,i-m[pre-k]);
            }
        }
    }
    return len;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    longestSubarraywithSum_K(a,n,k);
    return 0;
}
