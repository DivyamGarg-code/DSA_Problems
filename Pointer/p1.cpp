#include<bits/stdc++.h>
using namespace std;

int main(){
    int **arr;
    int r,c;
    cin>>r>>c;
    // creating the array of row heads
    arr=new int*[r];
    for(int i = 0; i < r; i++){
        arr[i]=new int[c]{0};
    }
    int val=1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            arr[i][j]=val;
            val++;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}