#include<bits/stdc++.h>
using namespace std;
/*
    N Queen Problem
    Expected Time Complexity: O(n!)
    Expected Auxiliary Space: O(n2) 
*/
bool isSafe(int row,int col,vector<vector<int>> &board,int n){
    int x=row;
    int y=col;
    while(y>=0){ // For row 
        if(board[x][y]==1){
            return false;
        }
        y--;
    }

    // x=row;
    // y=col;
    // while(x>=0){ // For column
    //     if(board[x][y]==1){
    //         return false;
    //     }
    //     x--;
    // }

    x=row;
    y=col;
    while(x>=0 && y>=0){ // For top left diagonal
        if(board[x][y]==1){
            return false;
        }
        y--;
        x--;
    }

    x=row;
    y=col;
    while(x<n && y>=0){ // For bottom left diagonal
        if(board[x][y]==1){
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int col,vector<vector<int>> &board,vector<vector<int>> &a,vector<int> ans,int n){
    if(col==n){
        a.push_back(ans);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            // if placing queen is safe
            ans.push_back(row+1);
            board[row][col]=1;
            solve(col+1,board,a,ans,n);
            // backtrack 
            ans.pop_back();
            board[row][col]=0;
        }
    }
}

void nQueens(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> a;
    vector<int> ans;
    solve(0,board,a,ans,n);
    for(auto x:a){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    nQueens(n);
    return 0;
}