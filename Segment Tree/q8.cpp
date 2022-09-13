#include<bits/stdc++.h>
using namespace std;

int hashFunction(string &s){
    int hash=0;
    for(int i=0;i<s.length();i++){
        hash+=(i+1)*(s[i]-'a'+1);
    }
    return hash;
}
int main(){
    // xwxx vztz
    // uwvy gvzz
    // tttt zszt
    // bvvv xxxw
    string a,b,c,d,e,f,g,h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    cout<<hashFunction(a)<<" "<<hashFunction(b)<<endl;
    cout<<hashFunction(c)<<" "<<hashFunction(d)<<endl;
    cout<<hashFunction(e)<<" "<<hashFunction(f)<<endl;
    cout<<hashFunction(g)<<" "<<hashFunction(h)<<endl;
    return 0;
}