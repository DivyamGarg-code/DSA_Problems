#include<bits/stdc++.h>
using namespace std;

/* MERGE K SORTED ARRAYS OF SIZE N

// Approach 1 create a vector and insert elements  then sort

 Approach 2 create a minHeap ,store the first element of all K arrays into minHeap 
   TC N*K(LOG(K))

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
        bool operator()(node* a,node*b){
            return a->data>b->data;
        }
};

int main(){
    vector<vector<int>> v;
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        vector<int> p;
        for(int j=0;j<k;j++){
            int temp;
            cin>>temp;
            p.push_back(temp);
        }
        v.push_back(p);
    }
    priority_queue<node*,vector<node*>,compare> minHeap;
    // step1 sare arrays ke 1st element insert karne han
    for(int i=0;i<k;i++){
        node* temp=new node(v[i][0],i,0);
        minHeap.push(temp);
    }
    // Time complexity of step 1: klog(k)
    // SC O(k) for this step
    vector<int> ans; 
    // step2 
    while(minHeap.size()>0){
        node* temp=minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int i=temp->i;
        int j=temp->j;
        if(j+1<v[i].size()){ // if the next index is smaller than the ith row vector size the proceed
            node* temp=new node(v[i][j+1],i,j+1);
            minHeap.push(temp);
        }
    }
    // As n*k-k elements left therfore TC for inserting and poping will be (n*k)*logk
    // SC for this step O(n*k)
    for(auto x:v){

    }
    return 0;
}
