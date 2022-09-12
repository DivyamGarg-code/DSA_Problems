#include<bits/stdc++.h>
using namespace std;
// spiral print of the 2D array  m-> rows n-> columns
/*  -->
    _________
    | ____  |
    ||    | |
    ||______|
*/
int main(){
    int r,c,m,n;
    cin>>r>>c;
    int a[r][c]={0};
    int val=1;
    for(int row = 0; row < r; row++){ // row wise traversal of array
        for(int col = 0; col < c; col++){
            a[row][col]=val;
            val+=1;
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    m=c-1; // columns
    n=r-1; // rows
    int N=r*c;
    int i=0;
    int cnt=0;
    cout<<" Value N : "<<N<<endl;
    while(cnt<=N){
        for(int col = i; col <=m; col++){ // col (right ->)
            cnt++;
            cout<<a[i][col]<<" ";
        }
        if(cnt==N){
            break;
        }
        cout<<" ";
        for(int row = i+1; row <=n; row++){ // row (downwards)
            cnt++;
            cout<<a[row][m]<<" ";
        }
        if(cnt==N){
            break;
        }
        cout<<" ";
        for(int col = m-1; col>=i; col--){ // col (left <-)
            cnt++;
            cout<<a[n][col]<<" ";
        }
        if(cnt==N){
            break;
        }
        cout<<" ";
        for(int row =n-1; row>=i+1; row--){ // row (upwards)
            cnt++;
            cout<<a[row][i]<<" ";
        }
        if(cnt==N){
            break;
        }
        cout<<" ";
        i+=1;
        m-=1;
        n-=1;
        
    }
    return 0;
}