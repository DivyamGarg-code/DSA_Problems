#include<bits/stdc++.h>
using namespace std;

string extractStringAtKey(string s,int key){
// you have typecast the string s to char* and 
// c_str() is a built in function in C++ which returns a pointer to an array that contains a 
//null-terminated sequence of characters representing the current value of the basic_string object.
    char *ptr=strtok((char *)s.c_str()," "); 
    while(key>1){
        ptr=strtok(NULL," ");
        key--;
    }
    return (string)ptr; // typecasted back to string
}
int convertToInt(string s){
    int ans=0;
    int p=1;
    for(int i =s.length()-1; i >=0 ; i--){
        ans+=p*(s[i]-'0'); // s[i]-'0' this will subtract the ASCII value of char 'int' - '0' giving correct digit
        p*=10;
    }
    return ans;

}
bool numericCompare(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return convertToInt(key1)<convertToInt(key2);
}

bool lexicoCompare(pair<string,string> s1,pair<string,string> s2){
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return key1<key2;
}

int main(){
    int n;
    cin>>n;
    cin.get();
    string s[100];
    for(int i = 0; i < n; i++){
        getline(cin,s[i]);
    }
    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;
    pair<string,string> strPair[100];
    for(int i = 0; i < n; i++){
        strPair[i].first=s[i];
        strPair[i].second=extractStringAtKey(s[i],key);
    }
    // Next is the sorting
    if(ordering=="numeric"){
        sort(strPair,strPair+n,numericCompare);
    }else{
        sort(strPair,strPair+n,lexicoCompare);
    }

    // For the reversal
    if(reversal=="true"){
        for(int i = 0; i < n/2; i++){
            // swap(srtPair[i],strPair[n-i-1]);
            pair<string,string> t=strPair[i];
            strPair[i]=strPair[n-i-1];
            strPair[n-i-1]=t;
            
        }
    }
    for(int i = 0; i < n; i++){
        cout<<strPair[i].first<<endl;
    }


    return 0;
}