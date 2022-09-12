#include<bits/stdc++.h>
using namespace std;
// sum of all the sub-matrices of a given matrix
// Maintaining a prefix sum column wise and row wise
// But there will be 4 nested loops which gives TC O(n^4) but 
// the space complexity will be O(1) if same array is manipulated 
// and O(n^2) if initiallised anather array of same size

int main(){
    int n,m,sum=0;
    cin>>n>>m;
    int a[n][m];
    int c[n][m]={0};
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin>>a[row][col];
        }
    }
    cout<<endl;  // i-> row j-> column
    for(int i = 0; i < n; i++){ // sum column wise
        c[i][0]=a[i][0];
        for(int j = 1; j < m; j++){
            c[i][j]=a[i][j]+c[i][j-1];   
        }
    }
    for(int j = 0; j <m; j++){ // sum row wise
        for(int i = 1; i < n; i++){
            c[i][j]=c[i][j]+c[i-1][j];   
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int l_i = 0; l_i < n; l_i++){ // extract all possible top left
        for(int l_j = 0; l_j < m; l_j++){ 
            //cout<<"top left : ("<<l_i<<","<<l_j<<")"<<endl;
            for(int b_i = l_i; b_i < n; b_i++){ // extract all possible bottom right
                for(int b_j = l_j; b_j < m; b_j++){
                    
                    if(l_i==0 && l_j!=0){
                        sum+=c[b_i][b_j]-c[b_i][l_j-1];
                    }else if(l_i!=0 && l_j==0){
                        sum+=c[b_i][b_j]-c[l_i-1][b_j];
                    }else if(l_i==0 && l_j==0){
                        sum+=c[b_i][b_j];
                    }else if(l_i!=0 && l_j!=0){
                        sum+=c[b_i][b_j]-c[l_i-1][b_j]-c[b_i][l_j-1]+c[l_i-1][l_j-1];
                    }

                    //cout<<"("<<b_i<<","<<b_j<<")"<<" sum : "<<sum;
                    
                    cout<<endl; 
                }
            }
            cout<<"\n";
        }
    }

   // cout<<" Final Sum of all the submatrices : "<<sum;
    return 0;
}

// sum+=c[b_i][b_j]-c[l_i-1][b_j]-c[b_i][l_j-1]+c[l_i-1][l_j-1];