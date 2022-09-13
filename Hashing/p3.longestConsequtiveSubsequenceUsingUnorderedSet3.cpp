#include<bits/stdc++.h>
using namespace std;

// Longest consecutive Subsequence using unordered map
// TC O(N)
// SC O(N)

int findLargestSeq(int a[],int n){
    unordered_set<int> s;
    int max_streak=0;
    for(int i=0;i<n;i++){
        s.insert(a[i]); // O(1) time
    }
    // iterating over all the elements and targeting those numbers from which the streak can start
    for(int i=0;i<n;i++){
        if(s.find(a[i]-1)==s.end()){ // ie we are not able to find the prev element: it could be the starting streak
            // a[i] is the starting point of the streak
            // traverse the entire range that is contained in that streak
            int next_no=a[i]+1;
            int streak_len=1;
            while(s.find(next_no)!=s.end()){
                next_no+=1;
                streak_len++;
            }
            max_streak=max(max_streak,streak_len);
        }
    }
    
}
int main(){
    int arr[]={14,5,1,2,6,3,7,8,9,13,15,11,12,13,17}; //10
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findLargestSeq(arr,n)<<endl;
    return 0;
}