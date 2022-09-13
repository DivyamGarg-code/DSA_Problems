#include<bits/stdc++.h>
using namespace std;
// first negative number in every window of size k
// TC O(n)
// SC O(number of negative numbers in the array)=O(n) worst case

// create a list of negative numbers
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    list<int> v;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(a[i]<0){
            v.push_front(i);
        }
    }
    for(auto x:v){
        cout<<a[x]<<" ";
    }
    cout<<endl;
    int i=0;
    int l=0;
    for(int j=k-1;j<n;j++){
        cout<<i<<" "<<j<<" ";
        if(v.empty()){
            cout<<0;
            ans.push_back(0);
        }else if(v.front()>=i && v.front()<=j){
            cout<<a[v.front()];
            ans.push_back(a[v.front()]);
            if(v.front()==i){
                v.pop_front();
            }
        }else if(v.front()>j){
            cout<<0;
            ans.push_back(0);
        }
        cout<<endl;
        i++;
    }

    return 0;
}