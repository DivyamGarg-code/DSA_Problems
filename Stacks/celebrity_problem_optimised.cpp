#include<bits/stdc++.h>
using namespace std;

/*

OPTIMISED SOLUTION HAVING TC : O(N) SC O(N)
USING STACK

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
    stack<int> s;
    int n,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        s.push(i);
        m.push_back(temp);
    }
    while(s.size()>1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(m[a][b]==1){ // if a knows b
            s.push(b);
        }else if(m[b][a]==1){ // if b knows a
             s.push(a);
        }
    }
    if(s.empty()){
        cout<<-1<<endl;
    }else{
        int c=s.top(); // Now check weathher this person is celebrity or not
        for(int i=0;i<n;i++){
            if(i!=c){ // diagonal elements 0 or 1 no matters
                if(m[c][i]!=0){ // row ke sare elements 0 hhone chahiye 
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i!=c){
                if(m[i][c]!=1){
                    cout<<-1<<endl;
                    return 0;
                }
            }
        }
        cout<<c<<endl;
    }

    return 0;
}
/*
BRUTE FORCE TC(n^2) SC O(1)
GOING TO EACH PERSON AND ASSUMING IT TO BE CELEBRITY

int main(){
    vector<vector<int>> m;
    int n,ans,cond1,cond2;
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
    for(int k=0;k<n;k++){
        cond1=1;
        cond2=1;
        int c=k; // Now check weathher this person is celebrity or not
        for(int i=0;i<n;i++){
            if(i!=c){
                if(m[c][i]!=0){ // row ke sare elements 0 hone chahiye
                    cond1=0;
                    break;
                }
            }
        }
        if(cond1!=0){
            for(int i=0;i<n;i++){ // column ke sare elements 1 hone chahiye except diagonal(yeh matter nhi karta)
                if(i!=c){ 
                    if(m[i][c]!=1){
                        cond2=0;
                        break;
                    }
                }
            }
            if(cond2!=0){
                cout<<k<<endl;
                return 0;
            }
        }
    }
    return 0;
}
*/