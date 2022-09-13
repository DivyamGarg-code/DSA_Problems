#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> maxHeap; // left part of median
    priority_queue<int,vector<int>,greater<int>> minHeap; // right part of median
    vector<double> v;
    int n;
    double median;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        int l=maxHeap.size();
        int r=minHeap.size();
        if(l==0 && r==0){
            maxHeap.push(data);
            median=data;
        }else if(l==r+1){
            if(data<maxHeap.top()){
                int temp=maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
                maxHeap.push(data);
                median=(minHeap.top()+maxHeap.top())/2.0;
            }else{
                minHeap.push(data);
                median=(minHeap.top()+maxHeap.top())/2.0;
            }
        }else if(l==r){
            if(data<minHeap.top()){
                maxHeap.push(data);
                median=maxHeap.top();
            }else{
                minHeap.push(data);
                median=minHeap.top();
            }
        }else if(r==l+1){
            if(data<=minHeap.top()){
                maxHeap.push(data);
                median=(minHeap.top()+maxHeap.top())/2.0;
            }else{
                int temp=minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
                minHeap.push(data);
                median=(minHeap.top()+maxHeap.top())/2.0;
            }
        }
        v.push_back(median);
    }

    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}