#include<bits/stdc++.h>
using namespace std;

// Smallest range in K lists 
//  Time Complexity : O(n * k *log k)
//  Auxilliary Space  : O(k)
// Optimised solution
/*
You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.
*/

class node{
    public:     
        int data;
        int i;
        int j;
        node(int data,int row,int col){
            this->data=data;
            i=row;
            j=col;
        }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data>b->data;
        }
};

bool minCompare(node* a,node* b){
    return a->data<b->data;
}

bool maxCompare(node* a,node* b){
    return a->data<b->data;
}

int main(){
    vector<vector<int>> v;
    int k,n;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        vector<int> p;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            p.push_back(temp);
        }
        v.push_back(p);
    }
    priority_queue<node*,vector<node*>,compare> minHeap;
    node* mini;
    node* maxi;
    // step1. create a min heap for starting element of each list and tracking min/max value
    for(int i=0;i<k;i++){
        node* temp=new node(v[i][0],i,0);
        minHeap.push(temp);
        if(i==0){
            maxi=temp;
            // cout<<mini->data<<" "<<maxi->data<<endl;
        }else{
            maxi=max(maxi,temp,maxCompare);
            // cout<<mini->data<<" "<<maxi->data<<endl;
        }
    }
    mini=minHeap.top();
    pair<int,int> p;
    p.first=mini->data;
    p.second=maxi->data;
    int range=maxi->data-mini->data+1;
    // process ranges
    while(!minHeap.empty()){
        node* temp=minHeap.top();
        minHeap.pop();
        int i=temp->i;
        int j=temp->j;
        if(j+1<n){
            node* n=new node(v[i][j+1],i,j+1);
            minHeap.push(n);
            maxi=max(maxi,n,maxCompare);
            mini=minHeap.top();
            if(range>maxi->data-mini->data+1){
                range=maxi->data-mini->data+1;
                p.first=mini->data;
                p.second=maxi->data;
            }
        }else{ // next element does not exist
            break;
        }
    }
    cout<<p.first<<" "<<p.second;
    return 0;
}