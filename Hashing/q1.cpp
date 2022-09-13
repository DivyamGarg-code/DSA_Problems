#include<bits/stdc++.h>
using namespace std;

// Find the smallest window in the string containing the characters of another string 
string find_window(string s,string p){
    int sl=s.length(); // string length
    int pl=p.length(); // pattern length
    int start_idx=-1;
    // 1. corner case 
    if(pl>sl){
        return "None";
    }
    // 2. create the frequency maps
    int FS[256]={0}; // frequency string 
    int FP[256]={0}; // frequency pattern
    for(int i=0;i<pl;i++){
        char ch=p[i];
        FP[ch]++;
    }
    // 3. SLIDING WINDOW (CONTRACTION AND EXPANSION + UPDATE THE MINIMUM LENGTH WINDOW)
    int cnt=0;
    int start=0; // left pointer for shrinking the window
    int min_len=INT_MAX;
    for(int i=0;i<sl;i++){
        char ch=s[i];
        FS[ch]++;
        // Maintain the count of characters matched
        if(FP[ch]!=0 && FS[ch]<=FP[ch]){
            cnt++;
        }

        // if all the characters matched
        if(cnt==pl){
            // start shrinking the window
            char temp=s[start];
            // loop to remove all unwanted characters
            while(FP[temp]==0 or FS[temp]>FP[temp]){
                FS[temp]--;
                start++;
                temp=s[start];
            }
            // window size
            int window_len=i-start+1;
            if(window_len<min_len){
                min_len=window_len;
                start_idx=start;
            }
        }   
    }
    if(start_idx=-1){
        return "None";
    }
    string ans=s.substr(start_idx,min_len);
    return ans;

}
int main(){
    string s="hlloeaeo world"; // string 
    string p="eelo"; // pattern
    cout<<find_window(s,p);
    return 0;
}