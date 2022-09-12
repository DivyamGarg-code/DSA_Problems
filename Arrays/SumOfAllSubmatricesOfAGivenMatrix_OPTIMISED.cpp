#include<bits/stdc++.h>
using namespace std;
// OPTIMISED SOLUTION
// HRE WE WILL SEE THE CONTRIBUTION OF EACH CELL IN THE FINAL SUM
// = a[i][j] * no. of submatrices this cell will be part of
// TC O(n^2)
// space complexity O(1)
int main(){
    int n,m,x,y,sum=0;
    cin>>n>>m;
    int a[n][m];
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin>>a[row][col];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            x=(i+1)*(j+1);
            y=(n-i)*(m-j);
            sum+=a[i][j]*(x*y);
        }
    }
    cout<<"sum : "<<sum;
    return 0;
}