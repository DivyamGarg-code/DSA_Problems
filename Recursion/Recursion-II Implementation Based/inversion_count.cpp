#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int s,int mid,int e){
    int n1=mid-s+1;
    int n2=e-mid;
    int temp[n1+n2];
    int i=s;
    int j=mid+1;
    int k=0;
    int cnt=0;
    while(i<=mid && j<=e){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
            k++;
        }else{
            temp[k++]=a[j++];
            cnt+=mid-i+1;
        }
    }
    // fill the array if some elemnts are left in the array
    while(i<=mid){
        temp[k++]=a[i++];
    }

    while(j<=e){
        temp[k++]=a[j++];
    }
    // Copy all the elements back to the array
    for(int i = 0; i <n1+n2; i++){
        a[s+i]=temp[i];
    }
    return cnt;
}

int inversion_count(int a[],int s,int e){
    if(s>=e){
        return 0;
    }
    int mid=s+(e-s)/2;
    int x=inversion_count(a,s,mid);
    int y=inversion_count(a,mid+1,e);
    int z=merge(a,s,mid,e);
    cout<<x<<" "<<y<<" "<<z<<endl;
    return x+y+z; 
}


int main(){
    int a[]={1,5,2,6,3,0};
    int n=sizeof(a)/sizeof(a[0]);
    int s=0;
    int e=n-1;
    cout<<inversion_count(a,s,e)<<endl;
    
    return 0;
}