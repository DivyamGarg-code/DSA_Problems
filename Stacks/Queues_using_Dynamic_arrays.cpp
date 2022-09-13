#include<bits/stdc++.h>
using namespace std;
// Implementation of queue
class Queue{
    private:
        int* a;
        int front=-1;
        int rear=-1;
        int max_size;
        int cnt=0;
    public:
        int isEmpty(){
            if(front==-1 && rear==-1){
                return 1;
            }
            return 0;
        }
        void print(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
            }else{
                int i=1;
                int j=front;
                while(i<=cnt){
                    cout<<a[j]<<" ";
                    j=(j+1)%max_size;
                    i++;
                }
                cout<<endl;
            }
        }
        void enqueue(int data){
            if(isEmpty()){
                max_size=1;
                a=new int[max_size];
                front=0;
                rear=0;
            }else if((rear+1)%max_size==front){ // is Full
                int* b=a;
                a=new int[2*max_size];
                int i=0;
                int j=front;
                while(i<cnt){
                    a[i]=b[j];
                    j=(j+1)%max_size;
                    i++;
                }
                max_size=2*max_size;
                rear=(rear+1)%max_size;
                delete []b;
            }else{
                rear=(rear+1)%max_size;
            }
            cnt+=1;
            a[rear]=data;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty can't delete further\n";
                return;
            }else{
                if(front==rear){
                    front=-1;
                    rear=-1;
                    return;
                }
                else{
                    cnt-=1;
                    front+=1;
                }
            }
        }
        int size(){
            return cnt;
        }
        int frontt(){
            return a[front];
        }
        
};

int main(){
    Queue p;
    for(int i=0;i<5;i++){
        p.enqueue(i);
        p.print();
        cout<<"Size --> "<<p.size()<<endl;
    }
    for(int i=0;i<3;i++){
        p.dequeue();
        p.print();
        cout<<"Size --> "<<p.size()<<endl;
    }
    for(int i=0;i<5;i++){
        p.enqueue(i+6);
        p.print();
        cout<<"Size --> "<<p.size()<<endl;
    }
    cout<<p.frontt();
    
    

    
}
