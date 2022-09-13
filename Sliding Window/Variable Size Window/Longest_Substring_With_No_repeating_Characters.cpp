#include<bits/stdc++.h>
using namespace std;
// dadbc  adbc 
// longest substring with no repeating character
void solve(string &s){
    int s_freq[256]={0};
    int i=0;
    int j=0;
    int s_idx=0;
    int max_size=0;
    int window_size;
    while(j<s.length()){
        char ch=s[j];
        if(s_freq[ch-'a']==0){
            s_freq[ch-'a']+=1;
            j++;
            
        }else{
            while(s_freq[ch-'a']!=0){
                char temp=s[i];
                s_freq[temp-'a']--;
                i++;
            }
        }
        window_size=j-i;
        if(window_size>max_size){
            s_idx=i;
            max_size=window_size;
        }
    }
    window_size=j-i;
    if(window_size>max_size){
        s_idx=i;
        max_size=window_size;
    }
    cout<<max_size<<endl;
    if(s_idx==-1){
        cout<<"String Dont exist\n";
    }else{
        cout<<s.substr(s_idx,max_size)<<" "<<max_size<<endl;
    }
}
int main(){
    string s;
    cin>>s;
    cout<<s.length()<<endl;
    solve(s);
    return 0;
}