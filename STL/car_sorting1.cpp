#include<bits/stdc++.h>
using namespace std;
// Problem : Sort the coordinates of a given cars in asceding order based upon their distance from origin
bool compare(pair<int,int> p1,pair<int,int> p2){
    int d1=p1.first*p1.first+p1.second*p1.second;
    int d2=p2.first*p2.first+p2.second*p2.second;
    if(d1==d2){ // sort acc. to x coordinate
        return p1.first<p2.first;
    }
    return p1<p2;
}
int main(){
    vector<pair<int,int>> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare);
    for(auto x:v){
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}