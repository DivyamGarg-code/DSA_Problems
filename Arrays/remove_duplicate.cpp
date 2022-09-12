#include<bits/stdc++.h>
using namespace std;
void removeduplicate(char a[]){
    char prev=a[0];
    for (int k = 0; a[k]!='\0'; k++){
        if(k==0){
            cout<<a[0];
        }else{
            if(prev!=a[k]){
                prev=a[k];
                cout<<a[k];
            }
        } 
    }

}
int main(){
    char a[1000];
    cin.getline(a,1000);
    removeduplicate(a);
}