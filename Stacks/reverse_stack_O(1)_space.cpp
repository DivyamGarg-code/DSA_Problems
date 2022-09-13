#include<bits/stdc++.h>
using namespace std;

/*
We can reverse a stack in O(1) time if we internally represent the stack 
as a linked list. Reverse a stack would require a reversing a linked list
which can be done with O(n) time and O(1) extra space.
Note that push() and pop() operations still take O(1) time. 
*/
class Node{
    public:
      //  friend class Stack;
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            next=NULL;
        }
};

class Stack{
    public:
        Node* head;
        Node* temp;
        int cnt;
        Stack(){
            head=NULL;
            temp=NULL;
            cnt=0;
        }
        void push(int data){ // insert the data in the beginening
            Node* n=new Node(data);
            if(head==NULL){
                head=n;
                temp=n;
            }else{
                n->next=head;
                head=n;
            }
            cnt+=1;
        }
        void pop(){
            if(temp!=NULL){
                Node* a=head;
                head=head->next;
                cnt-=1;
                delete a;
            }
        }
        int empty(){
            if(cnt==0){
                return 1;
            }
            return 0;
        }
        int size(){
            return cnt;
        }
        int top(){
            return head->data;
        }
        void reverse(){
            Node* Temp=head;
            Node* prev=NULL;
            Node* next=NULL;
            while(Temp!=NULL){
                next=Temp->next;
                Temp->next=prev;
                prev=Temp;
                Temp=next;
            }
            head=prev;
        }
        void display(){
            Node* Temp=head;
            while(Temp!=NULL){
                cout<<Temp->data<<endl;
                Temp=Temp->next;
            }
            cout<<endl;
        }

};




int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.reverse();
    s.display();
    return 0;

}

// void deleteMid(stack<int> &s,int mid){
//     if(mid==1){
//         s.pop();
//         return;
//     }
//     int temp=s.top();
//     s.pop();
//     deleteMid(s,mid-1);
//     s.push(temp);
// }