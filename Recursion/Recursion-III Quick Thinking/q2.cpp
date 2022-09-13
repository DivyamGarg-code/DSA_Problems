#include<bits/stdc++.h>
using namespace std;
// Number to spellings
void num_to_spel(string s[],int n){
    if(n==0){
        return;
    }
    int k=n%10;
    num_to_spel(s,n/10);
    cout<<s[k]<<" ";

}
int main(){
    string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n;
    cin>>n;
    num_to_spel(s,n);
    return 0;
}