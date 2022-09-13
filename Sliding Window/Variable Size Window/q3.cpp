#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1 && visited[i][j]==false){
                q.push({i,j});
                cnt+=1;
                visited[i][j]=true;
                while(!q.empty()){
                    pair<int,int> p=q.front();
                    q.pop();
                    int row=p.first;
                    int col=p.second;
                    cout<<"("<<row<<","<<col<<") ";
                    // check right
                    if(col+1<m){
                        if(a[row][col+1]==1 && visited[row][col+1]==false){
                            q.push({row,col+1});
                            visited[row][col+1]=true; 
                        }
                    }
                    // check bottom-right
                    if((row+1)<n && (col+1)<m){
                        if(a[row+1][col+1]==1 && visited[row+1][col+1]==false){
                            q.push({row+1,col+1});
                            visited[row+1][col+1]=true; 
                        }
                    }
                    // check down
                    if((row+1)<n){
                        if(a[row+1][col]==1 && visited[row+1][col]==false){
                            q.push({row+1,col});
                            visited[row+1][col]=true; 
                        }
                    }
                    // check bottom-left
                    if((row+1)<n && (col-1)>=0){
                        if(a[row+1][col-1]==1 && visited[row+1][col-1]==false){
                            q.push({row+1,col-1});
                            visited[row+1][col-1]=true; 
                        }
                    }
                }
                cout<<endl;
            }
        }
    }
    cout<<cnt;
    return 0;
}