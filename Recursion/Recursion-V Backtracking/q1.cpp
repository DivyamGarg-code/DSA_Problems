#include<bits/stdc++.h>
using namespace std;

int main(){
    char c[100];
    cin.getline(c,100);
    int max_size=0;
    // for(int i = 0; c[i]!='\0'; i++){
    //     cout<<c[i];
    // }
    // cout<<
    int s,e,temp=0,k=0;
    int idx[2]={0,0};
    s=e=0;
    for(int i = 0; c[i]!='\0'; i++){
        if(c[i]!=' '){
            if(k==0){
                s=i;
                
                e=i;
                k=1;
            }else{
                e+=1;
            }
            if(c[i+1]=='\0'){
                temp=e-s+1;
                if(temp%2==0 && temp>=max_size){
                    max_size=temp;
                    idx[0]=s;
                    idx[1]=e;
                }
            }
        }else{
            temp=e-s+1;
            if(temp%2==0 && temp>=max_size){
                max_size=temp;
                idx[0]=s;
                idx[1]=e;
            }
            k=0;
        }
    }
    for(int i = idx[0]; i <= idx[1]; i++){
        cout<<c[i];
    }

    return 0;
}