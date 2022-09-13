#include<bits/stdc++.h>
using namespace std;

/* Implementing stack using 2 queues
push() -> O(1)
pop() -> O(n)
top() -> O(n)
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
            q1.push(data);
        }
        void pop(){
            if(q1.empty()){
                return;
            }
            int n;
            n=q1.size();
            while(n>1){
                q2.push(q1.front());
                q1.pop();
                n--;
            }
            // remove the last element
            q1.pop();

            // swap the names of q1 and q2
            swap(q1,q2);
        }
        int top(){
            int n;
            n=q1.size();
            while(n>1){
                q2.push(q1.front());
                q1.pop();
                n--;
            }
            int last=q1.front();
            q2.push(last);
            q1.pop();
            swap(q1,q2);
            return last;
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
        cout<<s.top()<<endl;
        cout<<"Size -> "<<s.size()<<endl;
        s.pop();
    }
    s.pop();
    cout<<"Size -> "<<s.size()<<endl;
    return 0;
} 