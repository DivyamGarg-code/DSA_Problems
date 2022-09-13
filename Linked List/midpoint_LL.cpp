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
void insertNode(Node* &head,int index,int d){
    Node *n=new Node(d); // node to be inserted
    Node *temp=head; // conains the adress of 1st block (tail) which is inside the head[...] block
    int cnt=0;
    if(temp==NULL){
        if(cnt==index && index==0){
            head=n;
        }else{
            cout<<"Enter the correct index\n";
        }
    }
    while(temp!=NULL){
        if(cnt==index && index==0){ // insertion at the begining
            n->next=temp; // ie the new inserted node at 1st position will contain the address of next node
            head=n; // head now point to the new inserted element
            break;
        }else if(cnt==index-1 && index!=0){ // insertion at the middle
            if(temp->next!=NULL){
                n->next=temp->next;
                temp->next=n;
                break;
            }else{ // insertion at the end
                temp->next=n;
                break;
            }
        }else{
            cnt+=1;
            temp=temp->next; // store address of next node stored in the next pointer block at this address
        }
    }
    print(head);
}

void deleteNode(Node* &head,int index){ //  i_th index at which you want to delete
    Node* temp=head;
    Node* a=NULL;
    int cnt=0;
    if(temp==NULL){
        cout<<"As the list is empty you cant delete further\n";
    }
    while(temp!=NULL){
        if(cnt==index && index==0){ // deleting at the index 0
            a=temp;
            head=temp->next; // head now point to the 2nd node
            break;
        }else if(cnt==index-1 && index!=0){
            a=temp->next;
            temp->next=temp->next->next;
            break;
        }else{
            cnt+=1;
            temp=temp->next;
        }
    }
    delete a;
    print(head);
}
void midpoint_LL(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL){
        fast=fast->next->next;
        if(fast==NULL){
            break;
        }
        slow=slow->next;
    }
    cout<<"Midpoint : "<<slow->data;
}


int main(){
    Node* head=takeinput();
    midpoint_LL(head);
    return 0;
}