#include<bits/stdc++.h>
using namespace std;

// Min and Max stack along with the normal stack
// APPROACH 2
// get Min and Max element in O(1) Time and in O(1) space
class SpecialStack{
    // define thhe data members
    stack<int> s;
    int mini;
    public:
        void push(int data){
            if(s.empty()){
                mini=data;
                s.push(data);
            }else{
                if(data<mini){
                    mini=data;
                    s.push(2*data-mini);
                }else{
                    s.push(data);
                }
            }
        }
        int pop(){
            if(s.empty()){
                return -1;
            }
            int curr=s.top();
            s.pop();
            if(curr>mini){
                return curr;
            }
            else{
                int prevMin=mini;
                int val=2*mini-curr;
                mini=val; 
                return prevMin;

            }
        }
        int top(){
            if(s.empty()){
                return -1;
            }
            int curr=s.top();
            if(curr<mini){
                return mini;
            }else{
                return curr;
            }

        }
        bool isEmpty(){
            return s.empty();
        }
        int getMini(){
            if(s.empty()){
                return -1;
            }
            return mini;
        }
};
int main(){
    SpecialStack s;
    s.push(5);
    cout<<"Min "<<s.getMini()<<endl;
    s.push(3);
    cout<<"Min "<<s.getMini()<<endl;
    s.push(8);
    cout<<"Min "<<s.getMini()<<endl;
    s.push(2);
    cout<<"Min "<<s.getMini()<<endl;
    s.push(4);
    cout<<"Min "<<s.getMini()<<endl;
    return 0;
}