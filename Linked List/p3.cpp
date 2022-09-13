// Circular Linked List
// Here you can insert/delete at any i_th index including starting and ending
#include <bits/stdc++.h>
using namespace std;

class Node{   // [data,next]
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this->data=data;
        }
};

void print(Node* head){
    Node* temp=head;
    if(temp==NULL){
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
}
void insertatBeg(Node* &head,int data){
    Node* temp=head;
    Node* newnode=new Node(data);
    if(head==NULL){  
        head=newnode;
        newnode->next=head;
    }else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
}

// void deleteatEnd(Node* &head){
//     Node *temp=head;
//     Node* a=NULL;
//     if(head==NULL){
//         cout<<"LL is empty";
//     }else{
//         while(temp->next!=head){// traverse till the last node
//             temp=temp->next;
//         }
//         head=head->next;
//         temp->next=head;

//     }
// }