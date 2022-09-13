#include<bits/stdc++.h>
using namespace std;

// WILL RETURN THE INDEX OF THE ELEMENT JUST LESS THAN OR EQUAL TO THAT NUMBER
int  binarySearch(int a[],int n,int k){
    int s=3;
    int e=n-1;
    int mid;
    int idx=s;
    while(s<=e){
        mid=s+(e-s)/2;
        if(k==a[mid]){
            if(mid+1<=e){
                if(a[mid+1]==k){
                    s=mid+1;
                }else{
                    return mid;
                }
            }else{
                return mid;
            }
        }else if(k<a[mid]){
            e=mid-1;
        }else{
            idx=mid;
            s=mid+1;
        }
    }
    return idx;

}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<binarySearch(a,n,k);
    return 0;
}