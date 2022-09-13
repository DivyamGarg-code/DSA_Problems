#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(int stalls[],int n,int c,int min_sep){ // minimum seperation
    int lastCow=stalls[0];
    // place the first cow in the first stall 
    int cnt=1;
    for(int i = 1; i < n; i++){
        if(stalls[i]-lastCow>=min_sep){
            lastCow=stalls[i];
            cnt++;
        }
        if(cnt==c){
            return true;
        }
    }
    return false;
}

int main(){
    // Problem : Agressive Cows
    int stalls[]={1,2,4,8,9}; // after sorting | coordinates of stalls on x axis
    int n,cows; // n -> no. of stalls c-> n. of cows c<=n
    cin>>n>>cows;
    // Binary Search Algorithm
    int s=0; // minimum distance b/w 2 cows
    int e=stalls[n-1]-stalls[0]; // maximum distance b/w 2 cows
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2; // let's take this to be minimum distance between any 2 cows
        bool cowsRakhPaye=canPlaceCows(stalls,n,cows,mid);
        if(cowsRakhPaye){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    cout<<ans;

    return 0;
}