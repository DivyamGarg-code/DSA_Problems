#include<bits/stdc++.h>
using namespace std;

/*
    Finding the subsets/subsequences of a given string
    Input- "abc"
    Output- " ",a,ab,abc,ac,b,bc,c

    Here TC- log(n)*2^n   further when you study recursion then the time complexity will be reduced to 2^n
*/

void filterChars(int n,char a[]){
    int j=0;
    //string s="";
    while(n>0){
        int last_bit=(n&1);
        if(last_bit==1){
            cout<<a[j];
            //s+=a[j];
        }
        n=n>>1;
        j++;
    }
    cout<<endl;
}
void printSubsets(char a[]){
    int n=strlen(a);
    for(int i = 0; i < (1<<n); i++){
        filterChars(i,a);
    }
}
int main(){
    char a[100];
    cin.getline(a,100);
    printSubsets(a);
    
    return 0;
}

// You can store and sort them in the lexographic order also
/*
bool compare(string s1,string s2){
    return s1<s2; // comparing in lexographic order
}
string filterChars(int n,char a[]){
    int j=0;
    string s="";
    while(n>0){
        int last_bit=(n&1);
        if(last_bit==1){
            s+=a[j];
        }
        n=n>>1;
        j++;
    }
    return s;
}
void printSubsets(char a[]){
    int n=strlen(a);
    vector<string> v;
    v.reserve(1<<n);
    for(int i = 0; i < (1<<n); i++){
        v.push_back(filterChars(i,a));
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v){
       cout<<i<<endl; 
    }
}
*/