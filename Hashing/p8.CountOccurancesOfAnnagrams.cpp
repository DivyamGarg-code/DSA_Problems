#include<bits/stdc++.h>
using namespace std;
/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
*/
int search(string p, string s) {
    int sl=s.length();
    int pl=p.length();
    if(pl>sl){
        return 0;
    }
    int k=pl;
    int ans=0;
    int s_freq[256]={0};
    int p_freq[256]={0};
    for(int i=0;i<pl;i++){
        char ch=p[i];
        p_freq[ch]++;
    }
    int i=0;
    int j=0;
    int cnt=0;
    while(j<sl){
        char ch=s[j];
        s_freq[ch]++;
        if(p_freq[ch]!=0 && s_freq[ch]<=p_freq[ch]){
            cnt++;
        }
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            if(cnt==k){
                //cout<<s.substr(i,k)<<endl;
                ans+=1;
            }
            if(p_freq[s[i]]!=0){
                if(s_freq[s[i]]<=p_freq[s[i]]){ // Remember this
                    cnt--;
                }
            }
            s_freq[s[i]]--; 
            j++;
            i++;
        }
    }
    return ans;
}
int main(){
    string s;
    string p;
    cin>>s>>p;
    cout<<search(p,s);
    return 0;
}

// "abaacbabc"
// "abc"