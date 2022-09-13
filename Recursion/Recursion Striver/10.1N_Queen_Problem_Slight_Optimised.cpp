#include<bits/stdc++.h>
using namespace std;
// Optimizing isSafeFunction little bit
// TC O(n!)
// SC O(n^2)
bool isSafe(int row,int col,vector<int> &r_vis,vector<int> &c_vis,vector<int> d_tl_vis,vector<int> d_bl_vis,int n){
    if(r_vis[row]==0 && c_vis[col]==0 && d_tl_vis[(n-1)+(row-col)]==0 && d_bl_vis[(row+col)]==0){
        return true;
    }
    return false;
    
}

void solve(int col,vector<string> &board,vector<int> &r_vis,vector<int> &c_vis,vector<int> d_tl_vis,vector<int> d_bl_vis,int n,vector<vector<string>> &ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,r_vis,c_vis,d_tl_vis,d_bl_vis,n)){
            r_vis[row]=1;
            c_vis[col]=1;
            d_tl_vis[(n-1)+(row-col)]=1;
            d_bl_vis[(row+col)]=1;
            board[row][col]='Q';
            solve(col+1,board,r_vis,c_vis,d_tl_vis,d_bl_vis,n,ans);
            board[row][col]='.';
            r_vis[row]=0;
            c_vis[col]=0;
            d_tl_vis[(n-1)+(row-col)]=0;
            d_bl_vis[(row+col)]=0;
        }
    }
}
void solveNQueens(int n){
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;
    vector<int> r_vis(n,0);
    vector<int> c_vis(n,0);
    vector<int> d_tl_vis(2*n-1,0); 
    vector<int> d_bl_vis(2*n-1,0); 
    solve(0,board,r_vis,c_vis,d_tl_vis,d_bl_vis,n,ans);
    return;
}
int main(){
    int n;
    cin>>n;
    solveNQueens(n);
    return 0;
}