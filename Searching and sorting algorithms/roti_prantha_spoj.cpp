#include<bits/stdc++.h>
using namespace std;

bool isPossible(int c[],int l,int min_time,int p){
    int sum=0;
    for(int i = 0; i < l; i++){
        float a=((8.0*min_time)/c[i])+1;
        int b=(pow(a,0.5)-1)/2;
        sum+=b;   
    }
    if(sum>=p){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int p,l; // p-> no. of parathas  l-> no. of cooks
        cin>>p;
        cin>>l;
        int c[l]; // rating of cooks;
        for(int i = 0; i<l; i++){
            cin>>c[i];
        }
        int min_rank=c[0];
        for(int i = 1; i < l; i++){
            min_rank=min(min_rank,c[i]);
        }
        int start=0;
        int end=((p*(p+1))/2)*min_rank;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(c,l,mid,p)==true){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}