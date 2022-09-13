#include<bits/stdc++.h>
using namespace std;
// Implementation of queue
class Node{
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this->data=data;
        }

};
class Queue{
    private:
        Node* front=NULL; // like the head
        Node* rear=NULL;
        int cnt=0; // keep the count of the size of  Queue
    public:
        int isEmpty(){
            if(front==NULL){
                return 1;
            }
            return 0;
        }
        void print(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
            }else{
                Node *temp=front;
                while(temp!=NULL){
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
        void enqueue(int data){
            cnt+=1;
            Node* n=new Node(data);
            if(isEmpty()){
                front=n;
                rear=n;
            }else{
                rear->next=n;
                rear=n;
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty can't delete further\n";
                return;
            }else{
                cnt-=1;
                Node* del=front;
                front=front->next;
                delete del;
            }
        }
        int size(){
            return cnt;
        }
        int frontt(){
            return front->data;
        }
        
};

int main(){
    Queue p;
    for(int i=0;i<5;i++){
        p.enqueue(i);
        p.print();
        cout<<"Size --> "<<p.size()<<endl;
    }
    for(int i=0;i<6;i++){
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
