#include<bits/stdc++.h>
using namespace std;
// char *strtok(char *s, char *delimeter)
// returns a tokeon each subsequent call
// on the first call function should be passed with the string argument for 's'
// on the subsequent calls we should pass string argument as null
int main(){
    char s[100]="Hi my name i Divyam";
    char *ptr=strtok(s," ");
    cout<<ptr<<endl;
    while(ptr!=NULL){
        ptr=strtok(NULL," ");
        cout<<ptr<<endl;
    }
    
    return 0;
}