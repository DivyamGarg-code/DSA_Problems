#include<bits/stdc++.h>
using namespace std;
void solve(vector<pair<int,int>> v,int ans,int idx,int capacity){
    // base case 
    if(idx<0 || capacity==0){
        cout<<ans<<endl;
        return;
    }
    // rec case;
    if((capacity-v[idx].first)>=0){ // include
        ans+=v[idx].second;
        capacity-=v[idx].first;
        solve(v,ans,idx-1,capacity);
    }else{ // exclude
        solve(v,ans,idx-1,capacity);
    }

}
bool compare(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int main(){
    int n,c; 
    cout<<"Enter the size and max capacity of the theif's bag : ";
    cin>>n>>c;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int wt,price;
        cout<<"Enter wt and price of item no. "<<(i+1)<<" : ";
        cin>>wt>>price;
        v.push_back(make_pair(wt,price));
    }
    sort(v.begin(),v.end(),compare); // this will take nlogn time
    for(int i = 0; i < n; i++){
        cout<<"item no. "<<(i+1)<<" wt : "<<v[i].first<<" price : "<<v[i].second<<endl;
    }
    int ans=0;
    solve(v,ans,n-1,c); // Here n-1 is the index
    return 0;
}