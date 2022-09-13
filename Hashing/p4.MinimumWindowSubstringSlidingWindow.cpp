#include<bits/stdc++.h>
using namespace std;
// Very iMPORTANT QUESTION
// sliding window technique
// find the minimum length substring containing all the characters of a pattern
// TC O(s.length())
// SC O(1)
string slidingWindow(string s,string p){
    int sl=s.length(); // string length
    int pl=p.length(); // pattern length
    // 1. corner case 
    if(pl>sl){
        return "NONE";
    }
    // 2. create the frequency maps
    int s_freq[256]={0};
    int p_freq[256]={0};
    for(int i=0;i<pl;i++){
        p_freq[p[i]]++;
    }
     // 3. SLIDING WINDOW (CONTRACTION AND EXPANSION + UPDATE THE MINIMUM LENGTH WINDOW)
    int cnt=0;
    int start=0;  // left pointer for shrinking the window
    int start_idx=-1;
    int min_len=INT_MAX;
    for(int i=0;i<sl;i++){
        char ch=s[i];
        s_freq[ch]++;
        // Maintain the count of characters matched
        if(p_freq[ch]!=0 && s_freq[ch]<=p_freq[ch]){
            cnt++;
        }
        // if all the characters matched
        if(cnt==pl){
            // start shrinking the window
            char temp=s[start];
            //remove the unnecessary characters
            while(p_freq[temp]==0 || s_freq[temp]>p_freq[temp]){ 
                s_freq[temp]--;
                start++;
                temp=s[start];
            }
            // window size
            int window_len=i-start+1;
            if(window_len<min_len){
                min_len=window_len;
                start_idx=start;
            }
            // now go and find the next smaller window
            s_freq[temp]--;
            start++;
            cnt--;
        }
    }
    if(start_idx==-1){
        return "None";
    }
    string a=s.substr(start_idx,min_len);
    return a;
}
int main(){
    string s="timetopractice"; // string 
    string p="toc"; // pattern
    cout<<slidingWindow(s,p);
    return 0;
}