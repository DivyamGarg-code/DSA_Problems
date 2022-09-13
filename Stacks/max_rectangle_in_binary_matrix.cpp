#include<bits/stdc++.h>
using namespace std;
/*
    OPTIMISED SOLUTION
    Max Rectangle in Binary Matrix
    Using histogram area findiing approach using stacks
    TIME COMPLEXITY O(N*M)
    SPACE COMPLEXITY O(M)
*/
int* left(int v[],int m){
    stack<pair<int,int>> s;
    int* l_idx=new int[m];
    for(int i=0;i<m;i++){
        while(!s.empty() && (v[i]<s.top().first || v[i]==s.top().first)){
            s.pop();
        }
        if(s.empty()){
            l_idx[i]=-1;
        }else{
            l_idx[i]=s.top().second;
            
        }
        s.push(make_pair(v[i],i));
    }
    return l_idx;
}

int* right(int v[],int m){
    stack<pair<int,int>> s;
    int* r_idx=new int[m];
    for(int i=m-1;i>=0;i--){
        while(!s.empty() && (v[i]<s.top().first || v[i]==s.top().first)){
            s.pop();
        }
        if(s.empty()){
            r_idx[i]=-1;
        }else{
            r_idx[i]=s.top().second;
        }
        s.push(make_pair(v[i],i));
    }
    return r_idx;
}

int solve(int v[],int m){
    int area=INT_MIN;
    int ans,r_ans,l_ans;
    int* l=left(v,m); // array of indices for prev smaller element
    int* r=right(v,m); // // array of indices for next smaller element
    for(int i=0;i<m;i++){
        l_ans=0;
        r_ans=0;
        if(l[i]==-1){
            l_ans=i*v[i];
        }else{
            l_ans=(i-l[i]-1)*v[i];
        }
        if(r[i]==-1){
            r_ans=(m-i-1)*v[i];
        }else{
            r_ans=(r[i]-i-1)*v[i];
        }
        ans=l_ans+r_ans+v[i];
        area=max(area,ans);
    }
    return area;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!=0){
                a[i][j]+=a[i-1][j];
            }
        }
    }
    int b[m];
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[j]=a[i][j];
        }
        int area=solve(b,m);
        ans=max(ans,area);
    }
    cout<<ans;
    return 0;
}