#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int k,int r[][9],int c[][9],int m[][3][9]){
    if(r[row][k-1]==0 && c[k-1][col]==0 && m[row/3][col/3][k-1]==0){
        return true;
    }
    return false;
    
}

bool solve(vector<vector<int>>& sudoku,vector<pair<int,int>> v,int n,int r[][9],int c[][9],int m[][3][9],int i=0){
    if(i==n){
        for(auto x:sudoku){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int k=1;k<=9;k++){
        int x=v[i].first; // row 
        int y=v[i].second; // column
        if(isSafe(x,y,k,r,c,m)){
            sudoku[x][y]=k;
            r[x][k-1]=1;
            c[k-1][y]=1;
            m[x/3][y/3][k-1]=1;
            if(solve(sudoku,v,n,r,c,m,i+1)){
                return true;
            }else{
                r[x][k-1]=0;
                c[k-1][y]=0;
                m[x/3][y/3][k-1]=0;
                sudoku[x][y]=0;
            }
        }
    }
    return false;
}
void solveSudoku(vector<vector<int>>& sudoku){
    vector<pair<int,int>> v;
    int r[9][9]={0};
    int c[9][9]={0};
    int m[3][3][9]={0};
	for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                v.push_back({i,j});
            }else{
                r[i][sudoku[i][j]-1]=1;
                c[sudoku[i][j]-1][j]=1;
                m[i/3][j/3][sudoku[i][j]-1]=1;
            }
        }
    }
    int n=v.size();
    solve(sudoku,v,n,r,c,m);
    return;
}
int main(){
    vector<vector<int>> sudoku;
    for(int i=0;i<9;i++){
        vector<int> temp;
        for(int j=0;j<9;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        sudoku.push_back(temp);
    }
    cout<<endl;
    solveSudoku(sudoku);
    return 0;
}

// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9