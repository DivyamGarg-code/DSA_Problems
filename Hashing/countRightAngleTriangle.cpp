#include<bits/stdc++.h>
using namespace std;

// Count of Right-Angled Triangle formed from given N points whose base or perpendicular are parallel to X or Y axis
int countRightAngleTriangles(int a[][2],int n){
    int cnt=0;
    unordered_map<int,int> x;
    unordered_map<int,int> y;
    for(int i=0;i<n;i++){
        x[a[i][0]]++;
        y[a[i][1]]++;
    }
    for(int i=0;i<n;i++){
        int l_x=x[a[i][0]];
        int l_y=y[a[i][1]];
        if(l_x>=2 && l_y>=2){
            cnt+=(l_x-1)*(l_y-1);
        }
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    cout<<countRightAngleTriangles(a,n);
    return 0;
}