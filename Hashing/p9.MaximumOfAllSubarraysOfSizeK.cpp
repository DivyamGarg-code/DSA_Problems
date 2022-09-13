#include<bits/stdc++.h>
using namespace std;

// Maximum of all the subarrays of size k

/*
TIME COMPLEXITY O(N)
SPACE COMPLEXITY O(K)
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
*/
vector<int> solve(int a[],int n,int k){
    int i=0;
    deque<int> dq;
    int j=0;
    int ans=INT_MIN;
    vector<int> v;
    int temp=0;
    while(j<n){
        if(dq.empty()){
            dq.push_back(a[j]);
        }else{
            while(!dq.empty() && dq.back()<a[j]){
                dq.pop_back();
            }
            dq.push_back(a[j]);
        }
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            v.push_back(dq.front());
            if(dq.front()==a[i]){
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v=solve(a,n,k);
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}