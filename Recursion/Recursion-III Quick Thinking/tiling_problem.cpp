#include<bits/stdc++.h>
using namespace std;
// Place the tiles
//GIven a wall of size 4*N and tiles of size (1,4) and (4,1). In how many ways you can build the wall
int f(int n){ // number of ways
    if(n<=3){
        return 1;
    }
    return f(n-1)+f(n-4);
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
    return 0;
}