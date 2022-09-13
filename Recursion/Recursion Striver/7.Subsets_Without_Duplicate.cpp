#include<bits/stdc++.h>
using namespace std;

/*
SUBSET SUM ||
SUBSETS : REMOVING DUPLICATES
fIRST SORT THE ARRAY 
TC O(2^n*k)
Auxilary space complexity O(n)

*/ 
void solve(vector<int> &v,int n,vector<int> temp,int idx=0){
    for(auto x:temp){
        cout<<x<<" ";
    }
    cout<<endl;
    if(idx>=n){
        return;
    }
    for(int i=idx;i<n;i++){
        if(i>idx && v[i]==v[i-1]){
            continue;
        }
        temp.push_back(v[i]);// take
        solve(v,n,temp,i+1);
        temp.pop_back();
    }

}

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    vector<int> temp;
    solve(v,n,temp);
    return 0;
}

// void print(int a[],vector<int> temp,int n,int j=0,int sum=0){
//     if(j==n){
//         for(auto x:temp){
//             cout<<x<<" ";
//         }
//         // cout<<"Sum -> "<<sum;
//         cout<<endl;
//         return;
//     }
//     for(int i=j;i<n;i++){
//         if(i>j && a[i]==a[i-1]){
//             continue;
//         }
//         if(i==j){
//             print(a,temp,n,i+1,sum);
//             temp.push_back(a[i]);
//             print(a,temp,n,i+1,sum+a[i]);
//             temp.pop_back();
//         }
//     }  
// }