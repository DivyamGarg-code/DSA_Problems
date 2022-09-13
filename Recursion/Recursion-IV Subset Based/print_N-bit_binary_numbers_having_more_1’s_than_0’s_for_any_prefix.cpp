#include<bits/stdc++.h>
using namespace std;
void solve(int ones,int zeros,string output,int n){
    // base case
    if((ones+zeros)==n){
        cout<<output<<endl;
        return;
    }
    if(ones==0 || ((ones-zeros)==1) || (ones==zeros)){ // have only 1 choice
        string output1=output;
        output1.push_back('1');
        solve(ones+1,zeros,output1,n);
    }else if(ones>zeros ){
        string output1=output;
        string output2=output;
        output1.push_back('0');
        output2.push_back('1');
        solve(ones,zeros+1,output1,n);
        solve(ones+1,zeros,output2,n);
    }
    
}
int main(){
    int n;
    cin>>n;
    string output=""; // output
    solve(0,0,output,n);
    return 0;
}