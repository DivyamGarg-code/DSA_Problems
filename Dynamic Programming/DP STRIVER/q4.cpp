#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int key, int low, int high) {
    int max_limit = high;
    while(low<high) {
    int mid = low +(high-low)/2.0;
    if(v[mid]<key) {
    low = mid + 1;
    }
    else high = mid;
    }

    return high == max_limit ? -1 : high;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> visited(n,-1);
    sort(v.begin(),v.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        int key=v[i]+k;
        int idx=search(v,key,i+1,n);
        if(idx==-1){
            break;
        }else{
            if(visited[idx]==-1){ // not visited
                cnt++;
                visited[idx]=0;
            }else{
                int s=search(v,key,idx+1,n);
                if(s!=-1){
                    cnt++;
                    visited[s]=0;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}