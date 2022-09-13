#include<bits/stdc++.h>
using namespace std;

void solve(int o,int c,string s=""){
    if(o==0 && c==0){
        for(auto x:s){
            cout<<x;
        }
        cout<<endl;
        if(s.back()=='('){
            o+=1;
        }else{
            c+=1;
        }
        s.pop_back();
        return;
    }
    if(o==0){
        solve(o,c-1,s+')');
        return;
    }
    if(o<=c){
        solve(o-1,c,s+'(');
        solve(o,c-1,s+')');
        return;

    }else{
        return;
    }
}
int main(){
    int n;
    cin>>n;
    solve(n,n);
    return 0;
}