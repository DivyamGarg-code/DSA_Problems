#include<bits/stdc++.h>
using namespace std;

// maximum element deque
int main(){
    int n,k;
    cin>>n>>k;
    int* a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // we have to process 1st k elements seperately
    deque<int> Q(k);
    for(int i=0;i<k;i++){
        while(!Q.empty() && a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i); // we'll store the indices in the deque
    }
    // Process the remaining elements
    for(int i=k;i<n;i++){
        cout<<a[Q.front()]<<" "; // print thhe previous value
        // Remove the elements which are not the part of window (Contraction)
        while(!Q.empty() && Q.front()<=(i-k)){
            Q.pop_front();
        }
        // Remove thhe elements which are not useful and are in window
        while(!Q.empty() && a[Q.back()]<a[i]){
            Q.pop_back();
        }
        // Add the new elements (expansion)
        Q.push_back(i);
    }
    cout<<a[Q.front()]<<endl; // Printing the last index
    return 0;
}


// Brute force Time complexity O(n-k+1)k or O(nk)
// int main(){
//     int n,k;
//     cin>>n>>k;
//     int v[n];
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     for(int i=0;i<(n-k+1);i++){
//         int ans=INT_MIN;
//         for(int j=i;j<(k+i);j++){
//             ans=max(ans,v[j]);
//         }
//         cout<<ans<<" ";
//     }
//     return 0;
// }