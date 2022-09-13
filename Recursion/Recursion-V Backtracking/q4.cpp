#include<bits/stdc++.h>
using namespace std;
void findPath(vector<vector<int>> &m, int n,int i,int j,string op){
    // base case
    if(i==n-1 && j==n-1){
        cout<<op<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> m;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        m.push_back(temp);
    }
    string op="";
    findPath(m,n,0,0,op);
    return 0;
}