#include<bits/stdc++.h>
using namespace std;

void solve(string &s,vector<vector<int>> &palindrome,int i,vector<string> temp){
    if(i==s.size()){
        for(auto x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    for(int k=i;k<s.size();k++){
        if(palindrome[i][k]==1){
            temp.push_back(s.substr(i,k-i+1));
            solve(s,palindrome,k+1,temp);
            temp.pop_back();
        }
    }
}

void print(string &s){
    int n=s.length();
    vector<vector<int>> palindrome(n,vector<int>(n,-1));
    int cnt=n;
    int j;
    while(cnt){ // Store the bool value is the substring palindrome or not
        j=n-cnt;
        for(int i=0;i<cnt;i++){
            int len=j-i+1;
            if(s[i]==s[j]){
                if(len>3){
                    if(palindrome[i+1][j-1]==1){
                        palindrome[i][j]=1;
                    }else{
                        palindrome[i][j]=0;
                    }
                }else{
                    palindrome[i][j]=1;
                }
            }else{
                palindrome[i][j]=0;
            }
            j++;
        }
        cnt--;
    }
    vector<string> temp;
    solve(s,palindrome,0,temp);
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    print(s);
    return 0;
}