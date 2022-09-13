#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int area=INT_MIN;
    int n,ans,r_ans,l_ans;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++){
        l_ans=0;
        r_ans=0;
        for(int j=i-1;j>=0;j--){ // For left
            if(v[i]<=v[j]){
                l_ans=(i-j)*v[i];
            }else{
                break;
            }
        }

        for(int k=i+1;k<n;k++){ // For right
            if(v[i]<=v[k]){
                r_ans=(k-i)*v[i];
            }else{
                break;
            }
        }
        ans=l_ans+r_ans+v[i];
        area=max(area,ans);
    }
    cout<<area;

    return 0;
}