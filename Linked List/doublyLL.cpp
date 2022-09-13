// Doubly Linked List
// Here in my program insertion at index i only includes the insertion b/w beginning and
// the ending as for insertion at starting and ending,functions are seperately defined
#include <bits/stdc++.h>
using namespace std;
class Node{  // [prev,node,next]
    public:
        int data;
        Node* next=NULL;
        Node* prev=NULL;
        Node(int data){
            this->data=data;
        }
};

void display(Node* head){
    if(head==NULL){
        cout<<"List is empty\n";
    }
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" "; // display data at this address 
        temp=temp->next; // store address of next node stored in the next_pointer_block at this address
    }
    cout<<endl;
}
void insertatBeg(Node* &head,int data){
    Node* temp=head;
    if(head==NULL){
        Node* newnode=new Node(data);
        temp=newnode;
    }else{
        Node* newnode=new Node(data);
        head->prev=newnode;
        newnode->next=head;
        temp=newnode; 
    }
    head=temp;
    cout<<"After insertion at the beginning : ";
    display(head);
}
void insertatEnd(Node* &head,int data){
    Node *temp=head;
    Node *Temp=head;
    if(head==NULL){
        Node* newnode=new Node(data);
        Temp=newnode;
    }else{
        Node* newnode=new Node(data);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;

    }
    head=Temp;
    cout<<"After insertion at the end : ";
    display(head);
}
void insertatIndex(Node* &head,int i,int data){
    Node* temp=head;
    Node* newnode=new Node(data);
    int cnt=0;
    while(temp!=NULL){
        if(cnt==i-1){
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            break;
        }else{
            cnt+=1;
            temp=temp->next;
        }
    }
    cout<<"After insertion at the index "<<i<<" : ";
    display(head);
}
void deleteatBeg(Node* &head){
    Node* temp=head;
    if(temp==NULL){
        cout<<"List is empty\n";
        return;
    }else{
        if(temp->prev==NULL && temp->next==NULL){
            head=NULL;
        }else{
            head=head->next;
            temp->next->prev=NULL;
        }
        delete temp;
    }
    cout<<"After deletion at the begining : ";
    display(head);
}
void deleteatEnd(Node* &head){
    Node* temp=head;
    if(temp==NULL){
        cout<<"You can't delete further as the List is empty\n";
        return;
    }else{
        if(temp->prev==NULL && temp->next==NULL){
            head=NULL;
        }else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->prev->next=NULL;
            delete temp;
        }
    }
    cout<<"After deletion at the end : ";
    display(head);
}
void deleteatIndex(Node* &head,int i){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        if(cnt==i){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            break;
        }else{
            cnt+=1;
            temp=temp->next;
        }
    }
    delete temp;
    cout<<"After deletion at the index "<<i<<" : ";
    display(head);
}

void count(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt+=1;
        temp=temp->next;
    }
    cout<<"Number of nodes present are --> "<<cnt<<endl;
}

void reverse_Doubly_LL(Node* &head){
    Node* temp=head;
    if(temp==NULL){
        return;
    }
    else{ // swap prev and next adressses of all the nodes; [prev,data,next]
        while(temp->next!=NULL){
            Node* t=temp->next; 
            temp->next=temp->prev;
            temp->prev=t;
            temp=t; // this t will also stores the adress of next pointer as the link is broken
        }
        if(temp->next==NULL){ //  for the last node
            Node* t=temp->next;
            temp->next=temp->prev;
            temp->prev=t;
            head=temp;
        }
    }
    display(head);
}
int main(){
    Node* head=NULL;
    insertatBeg(head,32);
    insertatBeg(head,25);
    deleteatBeg(head);
    deleteatEnd(head);
    count(head);
    deleteatEnd(head);
    insertatEnd(head,5);   
    insertatEnd(head,340); 
    insertatIndex(head,1,100);  
    insertatBeg(head,0);
    count(head);
    deleteatIndex(head,2);

}