#include<bits/stdc++.h>
using namespace std;
/*

MORE OPTIMISED SOLUTION HAVING TC : O(n) SC O(1)
USING 2 POINTER APPROACH

Let’s say you ask from A that Do you know B?If A knows B => A can not be a celebrity.
If A does not know B then B can not be a celebrity.
So you strike out one name from your list, so on each question you can reject one name.
When there are only two people left in the list, then you will ask first person,
“Do you know the second person ?”. If he says yes then second person is the celebrity
and if he says no then the first person is the celebrity.
Thus you need to ask a maximum of n questions to correctly figure out celebrity name.
*/
int main(){
    vector<vector<int>> m;
    int n,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        m.push_back(temp);
    }
    int l=0;
    int r=n-1;
    while(l<r){
        if(m[l][r]==1){ // if l knows r that means r could be thhe celebrity
            l++;
        }else{ // that means l does not knows r therfore r can't be the celebrity
            r--;
        }
    }
    int c=l; // Now check weathher this person is celebrity or not
    for(int i=0;i<n;i++){
        if(m[c][i]!=0){ // row ke sare elements 0 hone chahiye
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){ // column ke sare elements 1 hone chahiye except diagonal(yeh matter nhi karta)
        if(i!=c){ 
            if(m[i][c]!=1){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}