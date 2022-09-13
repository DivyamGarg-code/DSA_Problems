#include<bits/stdc++.h>
using namespace std;

int solve(string s,int k){
    int sl=s.length();
    int s_freq[256]={0};
    int i=0;
    int j=0;
    int cnt=0;
    int max_size=0;
    int start_idx=-1;
    while(j<sl){
        char ch=s[j];
        if(s_freq[ch]==0){
            cnt++;
        }
        s_freq[ch]++;
        if(cnt<k){
            j++;
        }else if(cnt==k){
            // some condition
            int window_size=j-i+1;
            if(window_size>max_size){
                max_size=window_size;
                start_idx=i;
            }
            j++;
        }else if(cnt>k){ // contract the window till I get the size < or = k
            while(cnt>k){
                char temp=s[i];
                s_freq[temp]--;
                if(s_freq[temp]==0){
                    cnt--;
                }
                i++;
            }
        }
    }
    if(start_idx!=-1){
        return max_size;
    }else{
        return -1;
    }
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    cout<<solve(s,k);
    return 0;
}