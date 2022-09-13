#include<bits/stdc++.h>
using namespace std;

int findLargestSeq(int a[],int n){
    unordered_map<int,int> m; // unordered_map<number,streak_length>
    int len=1;
    for(int i=0;i<n;i++){
        if(m.count(a[i])==0){
            if(m.count(a[i]-1)==0 && m.count(a[i]+1)==0){ // neither left nor right consecutive number 
                m[a[i]]=1;
            }else if(m.count(a[i]-1)!=0 && m.count(a[i]+1)==0){ // as right part is not present therfore it is the new end of the streak which need to be updated and it's left consecutive number was the previous end therfore adding 1 to it
                m[a[i]]=1+m[a[i]-1]; // updating the new end
                int prev_len=m[a[i]-1];
                m[a[i]-prev_len]=m[a[i]]; // updating the old start

            }else if(m.count(a[i]-1)==0 && m.count(a[i]+1)!=0){ // as left part is not present therfore it is the new start of the streak which need to be updated and it's right consecutive number was the previous start therfore adding 1 to it
                m[a[i]]=1+m[a[i]+1]; // updating the new start;
                int prev_len=m[a[i]+1];
                m[a[i]+prev_len]=m[a[i]]; // updating the old end
            }else if(m.count(a[i]-1)!=0 && m.count(a[i]+1)!=0){
                m[a[i]]=1+m[a[i]+1]+m[a[i]-1];
                int left=m[a[i]-1];
                int right=m[a[i]+1];
                m[a[i]-left]=m[a[i]]; // updating the start
                m[a[i]+right]=m[a[i]]; // updating the end
            }
            len=max(len,m[a[i]]);
        }
    }
    return len;
}
int main(){
    int arr[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17}; //10
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findLargestSeq(arr,n)<<endl;
    return 0;
}