#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    int x,y;
    x=-1;
    y=-1;
    for(int i=0;i<n;i++){ // Find Ist index having 0
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                x=i;
                y=j;
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++){ // Set the row and column which can have 0a
        for(int j=0;j<m;j++){
            if(i!=x && j!=y){
                if(v[i][j]==0){
                    v[i][y]=0;
                    v[x][j]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){ //
        for(int j=0;j<m;j++){
            if(i!=x && j!=y){
                if(v[i][y]==0 || v[x][j]==0){
                    v[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){ // set that column 0
        v[i][y]=0;
    }
    for(int j=0;j<m;j++){ // set that row 0
        v[x][j]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}