#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int s=-1;
    int e=-1;
    int cur_sum;
    int max_sum=INT_MIN;
    cin>>n;
    int *a=new int[n];
    int c_sum[n]={0}; // cumulative sum
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    // Here the Time complexity: O(n^2)   Done by cumulative sum
    c_sum[0]=a[0];
    for (int i = 1; i < n; i++){
        c_sum[i]=c_sum[i-1]+a[i];
    }
    for (int i = 0; i < n; i++){
        cout<<c_sum[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i <n; i++){ 
        cur_sum=0;
        for (int j =i; j < n; j++){          
                cur_sum=c_sum[j]-c_sum[i-1];
                if(cur_sum>=max_sum){
                    max_sum=cur_sum;
                    s=i;
                    e=j;
                }
        }
    }

    cout<<max_sum<<endl;
    cout<<"Elements that give the max sum : ";
    for (int i = s; i <=e; i++)
    {
        cout<<a[i]<<" ";
    }
}



   // this is not optimized take more time --->Time complexity: O(n^3)
    // for (int i = 0; i <n; i++){
    //     for (int j =i; j < n; j++){
    //             cur_sum=0;
    //         for (int k =i; k<=j; k++){ // elements of subarray -> from i to j
    //             cur_sum+=a[k];
    //         }
    //         if(cur_sum>=max_sum){
    //             max_sum=cur_sum;
    //             s=i;
    //             e=j;
    //         }
    //     }
    // }