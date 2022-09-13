#include<bits/stdc++.h>
using namespace std;

// Impelementation of queue using circular array
class Queue{
    public:
        int *arr;
        int cs,ms,f=-1,r=-1;
        Queue(int ds=5){
            arr=new int[ds];
            cs=0;
            ms=ds;
        }
        bool full(){
            return cs==ms; 
        }
        bool empty(){
            return cs==0;
        }
        void push(int data){
            if(full()){
                cout<<"Stack is full\n";
            }else{
                if(empty()){
                    f=0;
                }
                r=(r+1)%ms;
                arr[r]=data;
                cs+=1;
            }
        }
        void pop(){
            if(empty()){
                cout<<"Stack is empty\n";
            }else{
                f=(f+1)%ms;
                cs-=1;
            }
        }
        int front(){
            return arr[f];
        }
        ~Queue(){
            if(arr!=NULL){
                delete []arr;
                arr=NULL;
            }
        }
};
int main(){
    Queue q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}