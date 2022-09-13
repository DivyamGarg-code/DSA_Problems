#include<bits/stdc++.h>
using namespace std;
/* RAT IN THE MAZE PROBLEM (you can move only right or in downward direction)
a) Find the path from src to dest
b) count the number of paths from src to dest
c) print all the possible paths
*/

// Here i and j -> current index : m,n -> desired destination
// true means 1 and false means zero
bool ratInMaze(char maze[10][10],int soln[][10],int i,int j,int m,int n){
    if(i==m && j==n){
        soln[m][n]=1;
        //Print the path
        for(int i = 0; i < m; i++){
            for(int j=0;j<n;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    // Rat should be inside the grid ie
    if(i>m || j>n){
        return false;
    }
    // if the current cell is blocked
    if(maze[i][j]=='X'){
        return false;
    }
    // Assume the solution exists through the current cell
    soln[i][j]=1;
    bool rightSuccess=ratInMaze(maze,soln,i,j+1,m,n);
    bool downSuccess=ratInMaze(maze,soln,i+1,j,m,n);
    // Backtracking
    soln[i][j]=0;

    if(rightSuccess || downSuccess){
        return true;
    }
    return false;

}
int main(){
    char maze[10][10]={
                        "0000",
                        "00X0",
                        "000X",
                        "0X00",
    };
    int soln[10][10]={0};

    return 0;
}