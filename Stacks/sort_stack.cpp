#include<bits/stdc++.h>
using namespace std;
// Approach 1
// Sort a stack using another stack
// Time Complexity O(n^2)
// Space Complexity O(n)
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl<<endl;
}
int main(){
    stack<int> s1;
    stack<int> s2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s1.push(x);
    }
    for(int i=1;i<n;i++){
        int temp=s1.top();
        s1.pop();
        int k=n-i;
        while(k>0){
            if(temp<s1.top()){
                s2.push(temp);
                temp=s1.top();
            }else{
                s2.push(s1.top());
            }
            s1.pop();
            k--;
        }
        s1.push(temp);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    print(s1);
    return 0;
}

// Approach 2
// int main(){
//     stack<int> s1;
//     stack<int> s2;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         s1.push(x);
//     }
//     while(!s1.empty()){
//         int temp=s1.top();
//         s1.pop();
//         if(s2.empty()){
//             s2.push(temp);
//         }else{
//             while(!s2.empty() && temp<s2.top()){
//                 s1.push(s2.top());
//                 s2.pop();
//             }
//             s2.push(temp);
//         }
//     }
//     while(!s2.empty()){
//         s1.push(s2.top());
//         s2.pop();
//     }
//     print(s1);
//     return 0;
// }