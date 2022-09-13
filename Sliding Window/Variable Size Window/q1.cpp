#include<bits/stdc++.h>
using namespace std;

void solve(string s,string p){
    int s_freq[26]={0};
    int p_freq[26]={0};
    int k=0;
    for(int i=0;i<p.length();i++){
        if(p_freq[p[i]-'a']==0){
            k+=1;
        }
        p_freq[p[i]-'a']+=1;
    }
    int min_size=INT_MAX;
    int s_idx=-1;
    int cnt=0;
    int i=0;
    int j=0;
    int window_size;
    while(j<s.length()){
        char ch=s[j];
        s_freq[ch-'a']++;
        if(p_freq[ch-'a']!=0 && s_freq[ch-'a']==p_freq[ch-'a']){
            cnt+=1;
        }
        if(cnt<k){
            j++;
        }else if(cnt==k){
            // Let's try to decrease the size
            while(cnt==k){
                char temp=s[i];
                s_freq[temp-'a']--;
                if(p_freq[temp-'a']!=0 && s_freq[temp-'a']<p_freq[temp-'a']){
                    cnt--;
                }
                i++;
            }
            window_size=j-i+2;
            if(window_size<min_size){
                min_size=window_size;
                s_idx=i-1;
            }
            j++;
        }
    }
    if(s_idx==-1){
        cout<<"String Dont exist\n";
    }else{
        cout<<s.substr(s_idx,min_size)<<" "<<min_size<<endl;
    }
}
int main(){
    string s,p;
    cin>>s>>p;
    solve(s,p);
    return 0;
}