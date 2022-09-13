#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,x;
    cin>>s>>x;
    int n=s.length();
    int m=x.length();
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]==x[j]){
            j++;
        }else{
            cout<<i<<" "<<j<<endl;
            j=0;
            if(s[i]==x[j]){
                j++;
            }
        }
        if(j==m){
            cout<<i-j+1;
            break;
        }
    }
    return 0;
}