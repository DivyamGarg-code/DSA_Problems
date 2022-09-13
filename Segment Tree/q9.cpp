#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top()<a[i]){
            pq.pop();
            pq.push(a[i]);
        }
    }
    while(!pq.empty()){
        int temp=pq.top();
        pq.pop();
        cout<<temp<<" ";
    }
    return 0;
}