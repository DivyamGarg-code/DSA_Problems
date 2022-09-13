#include<bits/stdc++.h>
using namespace std;

void storedOcc(int a[],int n,int key,vector<int> &b,int i=0){
    if(n==0){
        return;
    }
    if(a[0]==key){
        b.push_back(i);
    }
    return storedOcc(a+1,n-1,key,b,i+1);
}

void allOcc(int a[],int n,int key,int i=0){
    // base case
    if(n==0){
        return;
    }
    if(a[0]==key){
        cout<<i<<" ";
    }
    return allOcc(a+1,n-1,key,i+1);
}

// int lastOcc(int a[],int n,int key){
//     if(n==0){
//         return -1;
//     }
//     if(a[n-1]==key){
//         return n-1;
//     }
//     return lastOcc(a,n-1,key);
// }

// different style of writing the same function
int lastOcc(int a[],int n,int key){
    // base case
    if(n==0){
        return -1;
    }
    int i=lastOcc(a+1,n-1,key);
    if(i==-1){
        if(a[0]==key){
            return 0;
        }else{
            return -1;
        }
    }
    // otherwise if returned by subproblem is not -1
    return i+1;
}


// different style of writing the same function
int firstOcc(int a[],int n,int key){
    if(n==0){
        return -1;
    }
    // rec
    if(a[0]==key){
        return 0;
    }
    int i=firstOcc(a+1,n-1,key);
    if(i==-1){
        return -1;
    }
    return i+1;
}
int index(int a[],int n,int key,int i=0){
    if(n==0){
        return -1;
    }
    if(a[0]==key){
        return i;
    }
    return index(a+1,n-1,key,i+1);
    
}
int main(){
    int a[]={7,2,3,7,7,33,7,10};
    int n=sizeof(a)/sizeof(a[0]);
    int key;
    cin>>key;
    vector<int> b;
    storedOcc(a,n,key,b);
    // allOcc(a,n,key);
    for(auto x:b){
        cout<<x<<",";
    }
    return 0;
}