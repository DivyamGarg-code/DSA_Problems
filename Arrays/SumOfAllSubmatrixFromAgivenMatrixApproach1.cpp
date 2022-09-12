#include<bits/stdc++.h>
using namespace std;
// sum of all the sub-matrices of a given matrix
// Brute force - Extracting all the possible sub_matrices by taking top left corner (l_i,l_j)
// and bottom right corner (b_i,b_j)
// But there will be 6 nested loops which gives TC O(n^6) but the space complexity 
// will be O(1) as we are updating the value of sum variable

int main(){
    int n,m,sum=0;
    cin>>n>>m;
    int a[n][m];
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin>>a[row][col];
        }
    }
    cout<<endl;
    for(int l_i = 0; l_i < n; l_i++){ // extract all possible top left
        for(int l_j = 0; l_j < m; l_j++){ 

            // cout<<"top left : ("<<l_i<<","<<l_j<<")"<<endl;

            for(int b_i = l_i; b_i < n; b_i++){ // extract all possible bottom right
                for(int b_j = l_j; b_j < m; b_j++){

                    //cout<<"("<<b_i<<","<<b_j<<")"<<" ";

                    for(int i = l_i; i <=b_i; i++){ // for row
                        for(int j = l_j; j <= b_j; j++){ // for column
                            sum+=a[i][j];
                            cout<<a[i][j]<<" ";
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                }
            }
            cout<<"\n";
        }
    }

    cout<<" Final Sum of all the submatrices : "<<sum;
    return 0;
}