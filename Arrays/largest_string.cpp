#include<bits/stdc++.h>
using namespace std;

/* Q Read n, followed by n strings and print the largest string and its length
*/

int main(){
    int n;
    cout<<"Enter how many strings do you want to enter : ";
    cin>>n;
    cin.get(); // this will consume the /n from the buffer
    char a[1000];
    char largest[1000];
    int len=0;
    int max_len=0;
    for(int i=0;i<n;i++){
        cin.getline(a,1000);
        len=strlen(a);
        if(len>max_len){
            max_len=len;
            strcpy(largest,a); 
        }
    }
    cout<<largest<<" and "<<max_len;
    

}