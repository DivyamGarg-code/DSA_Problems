#include<bits/stdc++.h>
using namespace std;

int string_to_int(char a[],int n){
    if(n==0){
        return 0;
    }
    int digit=a[n-1]-'0'; // last digit
    int smaller_ans=string_to_int(a,n-1);
    return smaller_ans*10 +digit;
}
int main(){
    char a[]="1234";
    int len=strlen(a);
    cout<<string_to_int(a,len); 
    return 0;
}