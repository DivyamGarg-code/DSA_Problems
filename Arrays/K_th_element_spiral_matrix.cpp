// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//  matrix A[ ][ ], number of rows N, number of columns M, and integer K as input parameters and 
// returns the Kth element in the spiral traversal of the matrix.
 // } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int r, int c, int k){
        int m=c-1; // columns
        int n=r-1; // rows
        int N=r*c;
        int i=0;
        int cnt=0;
        while(cnt<=N){
            for(int col = i; col <=m; col++){ // col (right ->)
                cnt++;
                if(cnt==k){
                    return a[i][col];
                }
                if(cnt==N){
                    break;
                }
            }
            if(cnt==N){
                break;
            }
            for(int row = i+1; row <=n; row++){ // row (downwards)
                cnt++;
                if(cnt==k){
                    return a[row][m];
                }
            }
            if(cnt==N){
                break;
            }
            for(int col = m-1; col>=i; col--){ // col (left <-)
                cnt++;
                if(cnt==k){
                    return a[n][col];
                }
            }
            if(cnt==N){
                break;
            }
            for(int row =n-1; row>=i+1; row--){ // row (upwards)
                cnt++;
                if(cnt==k){
                    return a[row][i];
                }
            }
            if(cnt==N){
                break;
            }
            i+=1;
            m-=1;
            n-=1;
            
        }
    }

};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}  // } Driver Code Ends