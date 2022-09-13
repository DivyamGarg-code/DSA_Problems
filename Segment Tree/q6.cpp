#include<bits/stdc++.h>
using namespace std;

// void maxEvenSum(int a[],int &ans,vector<int> &temp,int i,int sum=0){
//     if(i<=0){
//         if((abs(sum)&1)==0){
//             ans=max(ans,sum);
//         }
//         return ;
//     }
//     temp.push_back(a[i-1]);
//     maxEvenSum(a,ans,temp,i-1,sum+a[i-1]); // includde
//     temp.pop_back();
//     maxEvenSum(a,ans,temp,i-1,sum); // not include
// }

void maxEvenSum(int a[],int &ans,int i,int sum=0){
    if(i<=0){
        if((abs(sum)&1)==0){
            ans=max(ans,sum);
        }
        return ;
    }
    maxEvenSum(a,ans,i-1,sum+a[i-1]); // includde
    maxEvenSum(a,ans,i-1,sum); // not include
}
int main(){
    int n;
    cin>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    maxEvenSum(a,ans,n);
    cout<<ans;
    return 0;
}