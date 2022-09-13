#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    char a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> p;
    vector<int> t;
    for(int i=0;i<n;i++){
        if(a[i]=='P'){
            p.push_back(i);
        }else{
            t.push_back(i);
        }
    }
    // for(auto x:p){
    //     cout<<x<<" ";
    // }
    // cout<<p.size()<<endl;
    // cout<<endl;
    // for(auto x:t){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // cout<<" Police ->"<<p[i]<<" Theif ->"<<t[j]<<" left ["<<left_range<<","<<p[i]<<")"<<" right ("<<p[i]<<","<<right_range<<"]"<<endl;
    int i=0;
    int j=0;
    int cnt=0;
    while(i<p.size() && j<t.size()){
        int left_range=p[i]-k;
        int right_range=p[i]+k;
        if(abs(p[i]-t[j])<=k){ // that means the thief lies in the range of policeman
            cnt+=1;
            i++;
            j++;
        }else{ // now check weather the theif lies it the range of police
            if(p[i]<t[j]){ // theif is ahead of policeman
                i++;
            }else{
                j++;
            }
            
        }
    }
    cout<<cnt;
    return 0;
}