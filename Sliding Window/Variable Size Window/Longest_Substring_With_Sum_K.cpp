#include<bits/stdc++.h>
using namespace std;

// LONGEST SUBSTRING WITH SUM K
void solve(string s,int k){
    int s_freq[26]={0};
    int cnt=0;
    int i=0;
    int j=0;
    int s_idx=-1;
    int max_size=0;
    while(j<s.size()){
        char ch=s[j];
        if(s_freq[ch-'a']==0){
            cnt+=1;
        }
        s_freq[ch-'a']+=1;
        if(cnt<k){
            j++;
            continue;
        }else if(cnt>k){
            while(cnt>k){
                char c=s[i];
                s_freq[c-'a']--;
                i++;
                if(s_freq[c-'a']==0){
                    cnt--;
                }
            }
        }else{
            int window_size=j-i+1;
            if(window_size>max_size){
                max_size=window_size;
                s_idx=i;
            }
            j++;
        }
    }
    if(s_idx==-1){
        cout<<"String Dont exist\n";
    }else{
        cout<<s.substr(s_idx,max_size);
    }
}
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    solve(s,k);
    return 0;
}