#include<bits/stdc++.h>
using namespace std;

// stock span problem
/*
Using stack APPROACH 2
Time Complexity: O(n). It seems more than O(n) at first look. 
If we take a closer look, we can observe that every element of the array 
is added and removed from the stack at most once. So there are total 2n 
operations at most. Assuming that a stack operation takes O(1) time, we 
can say that the time complexity is O(n).
Auxiliary Space: O(n) in the worst case when all elements are sorted in 
decreasing order.
*/
int main(){
    vector<int> v;
    vector<int> span;
    stack<int> s;
    int n,price;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>price;
        v.push_back(price);
    }
    for(int i=0;i<n;i++){
        if(i==0){
            s.push(i);
            span.push_back(1);
        }else{
            while(v[i]>=v[s.top()]){
                s.pop();
                if(s.empty()){ // Imp step
                    break;
                }
            }
            if(s.empty()){
                span.push_back(i+1);
                s.push(i);   
            }else{
                span.push_back(i-s.top());
                s.push(i);
            }
        }
    }
    for(auto x:span){
        cout<<x<<" ";
    }
    return 0;
}

/*
APPROACH 1
A Simple but inefficient method 
Traverse the input price array. For every element being visited, 
traverse elements on the left of it and increment the span value of it 
while elements on the left side are smaller.
The Time Complexity of the above method is O(n^2).
We can calculate stock span values in O(n) time.
*/

// int main(){
//     int n;
//     cin>>n;
//     int prices[n];
//     vector<int> span;
//     for(int i=0;i<n;i++){
//         cin>>prices[i];
//     }
//     span.push_back(1);
//     for(int i=1;i<n;i++){
//         int current_price=prices[i];
//         int k=0; // ie you are not able ot find
//         for(int j=i-1;j>=0;j--){
//             if(current_price<prices[j]){
//                 span.push_back(i-j);
//                 k=1;
//                 break;
//             }
//         }
//         if(k==0){
//             span.push_back(i+1);
//         }
//     }
//     for(auto x:span){
//         cout<<x<<" ";
//     }
// }