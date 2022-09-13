#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
        friend class Queue;
    public:
        Node(int data){
            this->data=data;
            next=NULL;
        }
};

class Queue{
    private:
        Node* head=NULL;
        Node* tail=NULL;
        int cs;
    public:
        Queue(){
            head=NULL;
            tail=NULL;
            cs=0;  
        }
        bool empty(){
            return  cs==0;
        }
        void push(int data){
            Node* n=new Node(data);
            if(head==NULL){
                head=n;
                tail=n;
            }else{
                tail->next=n;
                tail=n;
            }
            cs++;
        }
        void pop(){
            if(empty()){
                cout<<"Queue is empty\n";
            }else{
                Node* a=head;
                head=head->next;
                delete a;
                cs--;
            }
            
        }
        int front(){
            return head->data;
        }
        int size(){
            return cs;
        }
};
void print(Queue q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    Queue q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(7);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    print(q);
    return 0;
}