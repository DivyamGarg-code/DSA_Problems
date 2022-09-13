#include<bits/stdc++.h>
using namespace std;

// Printing Subsequences Using PowerSet
// TC O(2^n*l) where 2^n are the number of sub-srings and l is the length of each string 
// SC O(1)
int main(){
    string  s;
    cin>>s;
    int x=s.size();
    int n=(1<<x)-1;
    for(int k=1;k<=n;k++){
        int i=0;
        int j=k;
        string ans="";
        while(j>0){
            int a=j&1;
            if(a==1){
                ans.push_back(s[i]);
            }
            j=j>>1;
            i++;
        } 
        cout<<ans<<endl; 
    }
    return 0;
}

