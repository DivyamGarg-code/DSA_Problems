#include<bits/stdc++.h>
using namespace std;

// length of longest subarray with sum=0
// TC=O(N)
// SC=O(N)

int longestSubarraywith0Sum(vector<int>&a, int n){   
    unordered_map<int,int> m; // unordered_map<prefix_sum,first_index>
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++){
        pre+=a[i];
        if(m.count(pre)==0){
            if(pre==0){
                len=max(len,i+1);
            }else{
                m[pre]=i;
            }
        }else{
            len=max(len,i-m[pre]);
        }
    }
    return len;
}
int main(){
    int n;
    cin>>n;
    vector<int> a;
    cout<<longestSubarraywith0Sum(a,n);
    return 0;
}



class Node{
    public:
        int cnt;
        int mini;
        int maxi;
        // Node(int a,int b,int c){
        //     cnt=a;
        //     mini=b;
        //     maxi=c;
        // }
};






// int main(){
//     int n;
//     unordered_map<int,Node> m;

//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=1;i<n;i++){
//         a[i]+=a[i-1];
//     }
//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     for(int i=0;i<n;i++){
//         if(m.count(a[i])==0){
//             m[a[i]].cnt+=1;
//             m[a[i]].mini=i;
//             m[a[i]].maxi=i;
//         }else{
//             m[a[i]].cnt+=1;
//             m[a[i]].maxi=i;
//         }
//     }
//     int ans=0;
//     for(auto x:m){
//         if(x.second.cnt>=2 || x.first==0){
//             int a=x.second.mini;
//             int b=x.second.maxi;
//             cout<<x.first<<" "<<x.second.cnt<<" "<<a<<" "<<b<<endl;
//             if(x.first==0){
//                 ans=max(ans,b+1); // as b+1 will give the maximum length for 0
//             }else{
//                 ans=max(ans,b-a);
//             }
//         }
//     }
//     cout<<ans;
//     return 0;
// }