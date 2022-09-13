#include<bits/stdc++.h>
using namespace std;

/* Implementing stack using 2 queues
push() -> O(n)
pop() -> O(1)
top() -> O(1)
empty() -> O(1)
*/

class Stack{
    public:
        queue<int> q1;
        queue<int> q2;
        bool empty(){
            if(q1.empty()){
                return true;
            }
            return false;
        }
        void push(int data){
            if(q1.empty()){
                q1.push(data);
            }else{
                q2.push(data);
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
                swap(q1,q2);
            }
        }
        void pop(){
            if(q1.empty()){
                return;
            }
            q1.pop();
        }
        int top(){
            return q1.front();
        }
        int size(){
            return q1.size();
        }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top()<<endl;;
        s.pop();
    }

    return 0;
} 