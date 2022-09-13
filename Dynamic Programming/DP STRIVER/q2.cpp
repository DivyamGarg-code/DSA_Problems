#include<bits/stdc++.h>
using namespace std;

long long cnt=0;
void solve(vector<vector<char>> &v,int r,int c,int k,int i=0,int j=0,string s=""){
    if(k==0){
        cnt+=1;
        for(auto x:s){
            cout<<x;
        }
        cout<<endl;
        return;
    }
    if((i<0 || i>=r) || (j<0 || j>=c)){
        return;
    }
    s.push_back(v[i][j]);
    solve(v,r,c,k-1,i-1,j,s); // up
    solve(v,r,c,k-1,i+1,j,s); // down
    solve(v,r,c,k-1,i,j+1,s); // right
    solve(v,r,c,k-1,i,j-1,s); // left
    s.pop_back();
    return;
}
int main(){
    int r,c,k;
    cin>>r>>c>>k;
    vector<vector<char>> v;
    for(int i=0;i<r;i++){
        vector<char> temp;
        for(int i=0;i<c;i++){
            char ch;
            cin>>ch;
            temp.push_back(ch);
        }
        v.push_back(temp);
    }
    solve(v,r,c,k);
    cout<<cnt;
}