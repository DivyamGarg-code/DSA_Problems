
#include<bits/stdc++.h>
using namespace std;
// IMPORTANT :  Time complexity for Building a Binary Heap using heapify algorithm is O(n). 
// Building min heap TC O(n)
void heapify(vector<int> &a,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]<a[smallest]){
        smallest=left;
    }
    if(right<n && a[right]<a[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(a[i],a[smallest]);
        heapify(a,n,smallest);
    }
    
}
vector<int> buildMinHeap(vector<int> &arr){
    // Write your code here
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
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
    buildMinHeap(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}