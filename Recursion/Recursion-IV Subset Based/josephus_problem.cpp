#include<bits/stdc++.h>
using namespace std;
// Josephus Problem | Game of Death in a circle | Execution in Circle
int main(){
    int n,k;
    cin>>n>>k;
    int temp=0; // temp will have the trigger | temp is basically the index
    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back((i+1));
    }
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    while(n!=1){
        temp=(temp+k-1)%n;
        int idx=temp;
        v.erase(v.begin()+idx);
        temp=idx; // now the trigger goes to the next person(whose prev is dead)
        n--;
    }
    cout<<v[0];
    return 0;
}