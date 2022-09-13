#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int diff=0;
    int temp=v[0];
    for(int i=1;i<n;i++){
        cout<<temp<<" "<<v[i]<<endl;
        if(v[i]>temp){
            cout<<"case 1\n";
            if((v[i]-temp)>diff){
                diff=v[i]-temp;
            }
        }else{
            cout<<"case 2\n";
            temp=v[i];
        }
    }
    cout<<diff;
    return 0;
}