#include<bits/stdc++.h>
using namespace std;

int main(){
    // string s="I am using Hackerrank to improve programming";
    // string t="am Hackerrank to improve";
    // vector<string> p;
    // string S="Today is a rainy day";
    // char *ptr=strtok(s," "); // strtok(string,delimeter) return the adress of of string before delimeter
    // cout<<ptr<<endl;
    // while (ptr!=NULL)
    // {
    //     ptr=strtok(NULL," ");
    //     cout<<ptr<<endl;
    // }
    string S="Hi my name is Divyam";
    char s[S.length()+1];
    strcpy(s,S.c_str()); 
    char *ptr=strtok(s," ");
    cout<<ptr<<endl;
    while(ptr!=NULL){
        ptr=strtok(NULL," ");
        cout<<ptr<<endl;
    }

    return 0;
}