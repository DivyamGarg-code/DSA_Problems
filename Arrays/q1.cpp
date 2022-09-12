#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n,k,s; // k-> at each step strength s should always be greater than k  s-> current strength
    int step=1;
    cin>>n>>m>>k>>s;
    char a[n][m];
    for(int row = 0; row < n; row++){ // row wise traversal of array
        for(int col = 0; col < m; col++){
            cin>>a[row][col];
        }
    }
    for(int row = 0; row < n; row++){ // row wise traversal of array
        for(int col = 0; col < m; col++){
            if(s<k){
                cout<<"No";
                return 0;
            }
            if(a[row][col]=='.'){// strength decrease by 2
                if(col==0){
                    s-=2;
                }else{
                    s-=step;
                    s-=2; 
                }

            }else if(a[row][col]=='*'){// strength increase by 5
                if(col==0){
                    s+=5;
                }else{
                    s-=step;
                    s+=5;
                }
            }else if(a[row][col]=='#'){ // blocked move to next row without losing any pts
                if(col==0){
                    break;
                }else{
                    s-=step;
                    break;
                }
            }
        }
       
    }
    if(s>=k){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}