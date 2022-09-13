// Insertion and Deletion at the begining ,in b/w and at the end of the node 
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this->data=data;
        }
};
void print(Node* head){
    Node* Temp=head;
    while(Temp!=NULL){
        cout<<Temp->data<<" "; // print data at this address 
        Temp=Temp->next; // store address of next node stored in the next pointer block at this address
    }
    cout<<endl;
}

int count(Node* temp){
    if(temp==NULL){
        return 0;
    }
    temp=temp->next;
    return 1+count(temp);
}
Node* takeinput(){
    int data;
    cin>>data;
    Node *head=NULL; // point to the adress of 1st node
    Node *tail=NULL; // point to the adress of last node
    while(data!=-1){
        Node *newnode=new Node(data); // storing the data at this node --> [data,NULL] here newnode act as a head
        if(head==NULL){
            head=newnode; // head basically stores the address of 1st node
            tail=newnode;
        }else{ 
            tail->next=newnode;
            tail=tail->next; // or tail=next node

        }
        cin>>data;
    }
    return head;
}
void merge_2_sorted_LL(Node* l1,Node* l2){
    Node* h1=l1;
    Node* h2=l2;
    Node* head=NULL;
    Node* tail=NULL;
    while(h1!=NULL && h2!=NULL){
        if(h1->data<=h2->data){
            if(tail==NULL){
                head=h1;
                tail=h1;
            }else{
                tail->next=h1;
                tail=h1;
            }
            h1=h1->next;
        }else{
            if(tail==NULL){
                head=h2;
                tail=h2;
            }else{
                tail->next=h2;
                tail=h2;
            }
            h2=h2->next;
        }
    }
    while(h1!=NULL){
        tail->next=h1;
        tail=h1;
        h1=h1->next;
    }
    while(h2!=NULL){
        tail->next=h2;
        tail=h2;
        h2=h2->next;
    }
    print(head);
}



int main(){
    cout<<"Enter Linked list 1 : ";
    Node* l1=takeinput();
    cout<<"Enter Linked list 2 : ";
    Node* l2=takeinput();
    merge_2_sorted_LL(l1,l2);
    
    return 0;
}