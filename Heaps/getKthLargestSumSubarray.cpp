#include<bits/stdc++.h>
using namespace std;

// K-th Largest Sum Subarray
// TC O(n^2)
int getKthLargest(vector<int> &v, int k){
    int n=v.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    // Created the min heap
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=v[j];
            if(pq.size()<k){
                pq.push(sum);
            }else{
                if(sum>pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<getKthLargest(v,k);
    return 0;
}