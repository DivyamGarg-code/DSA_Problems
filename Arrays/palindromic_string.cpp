#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(char a[]){
    int s=0;
    int e=strlen(a)-1;
    while(s<=e){
        if(a[s]==a[e]){
            s++;
            e--;
        }else{
            return false;
        }
    }
    return true;
}


int main(){
    char a[1000];
    cin.getline(a,1000);
    if(ispalindrome(a)){
        cout<<"Palindromic String";
    }else{
        cout<<"Not a palindromic String";
    }
}