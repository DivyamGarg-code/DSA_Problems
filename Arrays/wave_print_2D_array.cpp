#include<bits/stdc++.h>
using namespace std;
// wave print of the 2D array  m-> rows n-> columns
/*      _____
    |___|   |___|
*/
int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n]={0};
    int val=1;
    for(int row = 0; row < m; row++){ // row wise traversal of array
        for(int col = 0; col < n; col++){
            a[row][col]=val;
            val+=1;
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int col = 0; col < n; col++){ // column traversal of array
            if(col%2==0){
                // even col-Top Down
                for(int row = 0; row < m; row++){
                    cout<<a[row][col]<<" ";
                }
            }else{
                // odd col-Top Down
                for(int row = 0; row < m; row++){
                    cout<<a[m-row-1][col]<<" ";
                }
            }
        cout<<"  ";
    }
    return 0;
}