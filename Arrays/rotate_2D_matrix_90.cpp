#include<bits/stdc++.h>
using namespace std;

void display(int a[][100],int n){
    cout<<endl;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotate(int a[][100],int n){
    // reverse each row
    for(int row = 0; row < n; row++){
        int start_Col=0;
        int end_Col=n-1;
        while(start_Col<end_Col){
            swap(a[row][start_Col],a[row][end_Col]);
            start_Col++;
            end_Col--;
        }
    }
    display(a,n);
    // to take transpose - which can be done by simply swapping the upper diagonal matrix with lower diagonal matrix
    for(int i = 0; i <n; i++){ // for row
        for(int j = i+1; j < n; j++){
            swap(a[i][j],a[j][i]);
        }
    }
    display(a,n);
}

void rotate_stl(int a[][100],int n){
    // same thing using stl reverse(start_container,end_container) methods
    for(int i = 0; i < n; i++){ // reverse each row
        reverse(a[i],a[i]+n); // here in 2D array a[i] means row pointer| a[i]+n ending pt.of that particular row
    }
    for(int i = 0; i <n; i++){ // for row
        for(int j = i+1; j < n; j++){
            swap(a[i][j],a[j][i]);
        }
    }
    display(a,n);

}
int main(){
    int a[100][100]={0};
    int n,m;
    cin>>n>>m;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
        }
    }
    int N=max(n,m);
    cout<<endl;
    //rotate_stl(a,N);
    rotate(a,N);
    
}