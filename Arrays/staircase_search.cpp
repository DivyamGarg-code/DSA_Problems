#include<bits/stdc++.h>
using namespace std;

/* Staircase Search - Searching a particular element in row wise and column wise sorted array
eg       1  4   8   10
         2  5   9   15
         6  16  18  20
         11 17  19  23  key =17

TC- O(n^2) Brute force applying linear search   traversing all rows and columns

TC- O(mlog(n))  Applying binary search on each row 
TC- O(nlog(m))  Applying binary search on each column

TC- O(n) Optimised approach see the 4 corner points  (1,23 these are useless) (11,10 are good)
 if we choose 10 ,as 17 is greater than 10 move down see as 17 is >15 ,move down as 17<20 move left
 ,as 17 <18 move left,as 17>16 move down as 17=17 stop :)
In worst case you can travel 2n steps which is proportional to n


*/

int main(){
    int n,m,key,start;
    cin>>n>>m>>key;
    int a[n][m];
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin>>a[row][col];
        }
    }
    for(int row = 0; row < n; row++){
        for(int col = m-1; col>=0; col--){
            start=a[row][col]; // starting staircase search from top right corner
            if(start==key){
                cout<<key<<" Present at index ("<<row<<","<<col<<")";
                return 0;
            }else if(start<key){
                break;
            }else{
                continue;
            }
        }
    }
    cout<<"Not present";
    return 0;
}