#include<bits/stdc++.h>
using namespace std;
// Kth Symbol in Grammar
void solve(int i,int n,int k,string output){
    // Base case 
    if(i-1==n){
        cout<<output[k-1]<<endl;
        return;
    }
    if(i==1){
        string output1=output;
        output1.push_back('0');
        solve(i+1,n,k,output1);
    }else{
        string output1=output;
        int N=output1.length();
        for(int i=0;i<N;i++){
            if(output1[i]=='0'){
                output1.push_back('1');
            }else if(output1[i]=='1'){
                output1.push_back('0');
            }
        }
        solve(i+1,n,k,output1);
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    string v="";
    solve(1,n,k,v);
    return 0;
}