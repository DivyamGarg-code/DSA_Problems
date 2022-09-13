#include<bits/stdc++.h>
using namespace std;

// Kth largest element using heap
// first build a min heap of size k
// then iterate from i=n-k to i=n elements checking if a[i]>heap.top() 
// then replace a[i] with a[0] and call heapify function to take it to its correct position

// BEST OPTIMISED TIME COMPLEXITY O(K + (N-K)LOG(K))
// SPACE COMPLEXITY O(1)
void heapify(vector<int>& v,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && v[left]<v[smallest]){
        smallest=left;
    }
    if(right<n && v[right]<v[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(v[smallest],v[i]);
        heapify(v,n,smallest);
    }
    
}
void buildHeap(vector<int>& v,int k){
    for(int i=k/2-1;i>=0;i--){
        heapify(v,k,i);
    }
}
int findKthLargest(vector<int>& v, int k) {
    int n=v.size();
    if(n==1){
        cout<<v[0]<<" ";
    }
    buildHeap(v,k);
    for(int i=k;i<n;i++){
        if(v[i]>v[0]){
            v[0]=v[i];
            heapify(v,k,0);
        }
    }
    cout<<v[0]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int k;
    cout<<"Enter the index : ";
    cin>>k;
    findKthLargest(v,k);
    return 0;
}

// Space complexity O(k)
// // arr : given array
//     // l : starting index of the array i.e 0
//     // r : ending index of the array i.e size-1
//     // k : find kth smallest element and return using this function
//     int kthSmallest(int arr[], int l, int r, int k) {
//         priority_queue<int> pq;
//         for(int i=0;i<k;i++){
//             pq.push(arr[i]);   
//         }
//         for(int i=k;i<=r;i++){
//             if(arr[i]<pq.top()){
//                 pq.pop();
//                 pq.push(arr[i]);
//             }
//         }
//         return pq.top();
//     }