#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

vector<int> findIndices(vector<int> q, vector<int> a, int x){
    vector<int> op;
    vector<pair<int,int>> c;
    for(int i = 0; i < a.size(); i++){
        c.push_back(make_pair(a[i],(i+1)));
    }
    sort(c.begin(),c.end(),compare);
    vector<int> d; // sorted array
    vector<int> idx; // indeces stored
    for(int i = 0; i < a.size(); i++){
        d.push_back(c[i].first);
    }
    for(int i = 0; i < a.size(); i++){
        idx.push_back(c[i].second);
    }
    for(int i = 0; i < q.size(); i++){
        bool present=binary_search(d.begin(),d.end(),x);
        if(present){
            auto lb=lower_bound(d.begin(),d.end(),x);
            auto ub=upper_bound(d.begin(),d.end(),x);
            int f=(ub-lb);
            if(f>=q[i]){
                int l=lb-d.begin();
                int z=l+(q[i]-1);
                op.push_back(idx[z]);
            }else{
               op.push_back(-1); 
            }

        }else{
            op.push_back(-1);
        }
    }
    return op;
}

int main(){
    int X;
    cin>>X;
    vector<int> op;
    vector<int> a= {1, 2, 20, 8, 8, 1, 2, 5, 8, 0};
    vector<int> q={100,4,2};
    vector<pair<int,int>> c;
    vector<int> output;
    output=findIndices(q,a,X);
    
    for(auto p:output){
        cout<<p<<" ";
    }

    return 0;
}