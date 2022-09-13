#include<bits/stdc++.h>
using namespace std;

/* combinational sum 2 :  DDONT PRINT DUPLICATES
 Brute Force: USE A SET which basically removes the duplicates if any.
 THEN THE TIME COMPLEXITY WOULD BE O(2^n*k*logn) where 2^n ->possible subsequences if all are different and klogn would be TC of storing each subsequence of average lenght k
 Time complexity exponential O(2^n*k) where k is the average length of eachsubsequence
 Space complexity (x*t)
*/
void solve(int a[],int n,vector<int> temp,int target,int idx=0){
     if(target==0){
        for (auto x:temp){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
     }
     for(int i=idx;i<n;i++){
         if(i>idx && a[i]==a[i-1]){
            continue;
         }
         if(a[i]>target){
            break;
         }
         temp.push_back(a[i]);
         solve(a,n,temp,target-a[i],i+1);
         temp.pop_back();
     }
}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    vector<int> temp;
    solve(a,n,temp,k);
    return 0;
}