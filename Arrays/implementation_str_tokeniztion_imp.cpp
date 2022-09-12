#include<bits/stdc++.h>
using namespace std;
// char *strtok(char *s, char *delimeter)
// returns a tokeon each subsequent call
// on the first call function should be passed with the string argument for 's'
// on the subsequent calls we should pass string argument as null

char* mystrtok(char *str,char delim){

    static char *input=NULL; // this static variable will make like a global variable ie the value can be changed over and over
    if(str!=NULL){ 
        input=str;
    }
    if(input==NULL){
        return NULL;
    }
    // start extracting tokens and store them in an array
    char *output=new char[strlen(input)+1]; // +1 is reserved for the null character
    int i = 0;
    for( ;input[i]!='\0'; i++){
        if(input[i]!=delim){
            output[i]=input[i];
        }else{
            output[i]='\0';
            input=input+(i+1); // this will update the input to the string next after the delimeter
            return output;
        }
    }
    output[i]='\0';
    input=NULL;
    return output;
    

}
int main(){
    char s[100]="Today is a rainy day";
    char *ptr=mystrtok(s,' ');
    cout<<ptr;
    while (ptr!=NULL){
        ptr=mystrtok(NULL,' ');
        cout<<ptr<<endl;
    }
    



    // char *ptr=strtok(s," "); // strtok(string,delimeter) return the adress of of string before delimeter
    // cout<<ptr<<endl;
    // while (ptr!=NULL)
    // {
    //     ptr=strtok(NULL," ");
    //     cout<<ptr<<endl;
    // }
    return 0;
}