#include<bits/stdc++.h>
using namespace std;

bool compare(string a,string b){ // comparing string on the bases of length
    if(a.length()==b.length()){
        return a<b; // lexicographical/alphabatical order sorting 
    }
    return a.length()<b.length();
}
int main(){
    int n;
    cin>>n;
    cin.get(); // will consume if \n present in the buffer 
    string s[100];
    for(int i = 0; i < n; i++){
        getline(cin,s[i]);

    }
    // sort(s,s+n); // lexographically sort karega 
    sort(s,s+n,compare); // on the bases of length sort karega 
    for(int i = 0; i < n; i++){
        cout<<s[i]<<endl;
    }

   
    
}
