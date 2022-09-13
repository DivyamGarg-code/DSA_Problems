#include<bits/stdc++.h>
using namespace std;

// Rat in the Maze
bool isSafe(vector<vector<int>> &m,vector<vector<int>> &visited,int new_x,int new_y,int n){
    if((new_x>=0 && new_x<n) && (new_y>=0 && new_y<n) && (m[new_x][new_y]==1) && (visited[new_x][new_y]==0)){
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &m,vector<vector<int>> &visited,vector<string> &ans,int n,int x=0,int y=0,string s=""){
    if(x==n-1 && y==n-1){
        ans.push_back(s);
        return;
    }
    visited[x][y]=1;
    if(isSafe(m,visited,x+1,y,n)){ // check for down movement;
        s.push_back('D');
        solve(m,visited,ans,n,x+1,y,s);
        s.pop_back();
    }

    if(isSafe(m,visited,x,y-1,n)){ // check for left movement;
        s.push_back('L');
        solve(m,visited,ans,n,x,y-1,s);
        s.pop_back();
    }

    if(isSafe(m,visited,x,y+1,n)){ // check for right movement;
        s.push_back('R');
        solve(m,visited,ans,n,x,y+1,s);
        s.pop_back();
    }

    if(isSafe(m,visited,x-1,y,n)){ // check for up movement;
        s.push_back('U');
        solve(m,visited,ans,n,x-1,y,s);
        s.pop_back();
    }
    visited[x][y]=0;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> m;
    for(int i=0;i<n;i++){
        vector<int> temp;
        temp.reserve(n);
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        m.push_back(temp);
    }
    vector<vector<int>> visited(n,vector<int>(n,0));
    vector<string> ans;
    if(m[0][0]==0){ // edge case 
        cout<<"No Possible path as the 1st position is blocked\n";
    }else{
        solve(m,visited,ans,n,0,0);
        for(auto x:ans){
            cout<<x<<" ";
        }
    }
    return 0;
}