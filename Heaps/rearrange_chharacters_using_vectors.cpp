#include<bits/stdc++.h>
using namespace std;

// Rearrange characters 
// USING vectors
/*
Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same.
Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

TIME COMPLEXITY O(NLOGN)
SPACE COMPLEXITY O(SIZE OF THE STRING)
*/

bool compare(pair<char,int> a,pair<char,int> b){
    return a.second>b.second;
}

int main(){
    string s;
    cin>>s;
    char arr[s.size()];
    sort(s.begin(),s.end());
    int freq=0;
    char ch;
    vector<pair<char,int>> v;
    for(int i=0;i<s.size();i++){
        if(i==0){
            ch=s[i];
            freq+=1;
        }else{
            if(s[i]==ch){
                freq+=1;
            }else{
                v.push_back(make_pair(ch,freq));
                ch=s[i]; // update the character
                freq=1; // update the frequency of that character
            }
        }
    }
    v.push_back(make_pair(ch,freq));
    sort(v.begin(),v.end(),compare);
    int n=s.size();
    int k=0;
    if(n%2==0){ // n is even
        if(v[k].second<=(n/2)){
            for(int i=0;i<n;i+=2){
                if(v[k].second!=0){
                    arr[i]=v[k].first;
                    v[k].second--;
                }else{
                    k++;
                    arr[i]=v[k].first;
                    v[k].second--;
                }
            }
            for(int i=1;i<n;i+=2){
                if(v[k].second!=0){
                    arr[i]=v[k].first;
                    v[k].second--;
                }else{
                    k++;
                    arr[i]=v[k].first;
                    v[k].second--;
                }
            }
            for(int i=0;i<n;i++){
                s[i]=arr[i];
            }
        }else{
            cout<<"Not Possible\n";
        }
    }else{ // nis odd
        if(v[k].second<=(n+1)/2){
            for(int i=0;i<n;i+=2){
                if(v[k].second!=0){
                    arr[i]=v[k].first;
                    v[k].second--;
                }else{
                    k++;
                    arr[i]=v[k].first;
                    v[k].second--;
                }
            }
            for(int i=1;i<n;i+=2){
                if(v[k].second!=0){
                    arr[i]=v[k].first;
                    v[k].second--;
                }else{
                    k++;
                    arr[i]=v[k].first;
                    v[k].second--;
                }
            }
            for(int i=0;i<n;i++){
                s[i]=arr[i];
            }
        }else{
            cout<<"Not Possible\n";
        }
    }
    
    return 0;
}