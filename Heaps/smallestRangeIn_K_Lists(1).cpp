#include<bits/stdc++.h>
using namespace std;

// Smallest range in K lists 
// Time complexity O(n*k^2)
// space complexity O(K)
// Not an optimised solution
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
    vector<node*> a;
    node* mini;
    node* maxi;
    for(int i=0;i<k;i++){
        node* temp=new node(v[i][0],i,0);
        a.push_back(temp);
        if(i==0){
            mini=temp;
            maxi=temp;
            // cout<<mini->data<<" "<<maxi->data<<endl;
        }else{
            mini=min(mini,temp,minCompare);
            maxi=max(maxi,temp,maxCompare);
            // cout<<mini->data<<" "<<maxi->data<<endl;
        }
    }
    pair<int,int> p;
    p.first=mini->data;
    p.second=maxi->data;
    int range=maxi->data-mini->data+1;
    while(1){
        node* temp=mini;
        int i=temp->i;
        int j=temp->j;
        if(j+1<n){
            node* n=new node(v[i][j+1],i,j+1);
            a[i]=n;
            for(int i=0;i<k;i++){
                if(i==0){
                    mini=a[i];
                    maxi=a[i];
                }else{
                    mini=min(mini,a[i],minCompare);
                    maxi=max(maxi,a[i],maxCompare);
                }
            }
            if(range>maxi->data-mini->data+1){
                range=maxi->data-mini->data+1;
                p.first=mini->data;
                p.second=maxi->data;
            }
        }else{
            break;
        }
    }
    cout<<p.first<<" "<<p.second;
    return 0;
}