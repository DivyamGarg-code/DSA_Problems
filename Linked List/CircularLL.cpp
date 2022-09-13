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
    if(head==NULL){
        cout<<"List is empty\n";
        return;
    }
    Node* temp=head;
    do{
        cout<<temp->data<<" "; // print data at this address 
        temp=temp->next; // store address of next node stored in the next_pointer_block at this address
    }while(temp!=head);
    cout<<endl;
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
        newnode->next=head;
        head=newnode;
        temp->next=head;// last node will point to the new node inserted at 1st index
    }
}
void insertatEnd(Node* &head,int data){
    Node *temp=head;
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }else{
        while(temp->next!=head){// traverse till the last node
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

    }
}
void insertatIndex(Node* &head,int i,int data){
    bool b=false;
    int c=0;
    Node* temp=head;
    Node* newnode=new Node(data);
    int cnt=0;
    if(i==0){ // insertion at index 0
        b=true;
        insertatBeg(head,data);
    }else{
        while(temp->next!=head){ // insertion at i_th index
            if(cnt==i-1 && i>0){
                c=1;
                newnode->next=temp->next;
                temp->next=newnode;
                b=true;
                break;
            }else{
                cnt+=1;
                temp=temp->next;
            }
        }
        if(cnt==i-1 && c==0){
            b=true;
            insertatEnd(head,data);
        }
    } 
    if(b==true){
        cout<<"After insertion at the index "<<i<<" : ";
        print(head);
    }else{
        cout<<"Enter correct index\n";
    }
    
 }
void deleteatBeg(Node* &head){
    Node* temp=head;
    Node* a=temp;
    if(temp==NULL){
        cout<<"List is empty\n";
        return;
    }else{
        if(temp->next==head){
            head=NULL;
        }else{
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=head->next;
            head=head->next;
            
        }
        delete a;
    }
}
void deleteatEnd(Node* &head){
    Node* temp=head;
    Node* a=NULL;
    if(temp==NULL){
        cout<<"You can't delete further as the List is empty\n";
        return;
    }else{
        if(temp->next==head){
            head=NULL;
        }else{
            while(temp->next->next!=head){
                temp=temp->next;
            }
            a=temp->next;
            temp->next=head;
        }
        delete a;
    }
}
void deleteatIndex(Node* &head,int i){
    Node* a=NULL;
    bool b=false;
    int c=0;
    Node* temp=head;
    int cnt=0;
    if(i==0){ // deletion at index 0
        b=true;
        deleteatBeg(head);
    }else{
        while(temp->next!=head){ //deletion at the index i
            if(cnt==i-1){
                a=temp->next;
                b=true;
                temp->next=temp->next->next;
                c=1;
                break;
            }else{
                cnt+=1;
                temp=temp->next;
            }
        }
        delete a;
        if(cnt=i-1 && c==0){ // deletion at the end
            b=true; 
            deleteatEnd(head);
        }
    } 
    if(b==true){
        cout<<"After deletion at the index "<<i<<" : ";
        print(head);
    }else{
        cout<<"Enter correct index\n";
    }    
}

void reverse_circular_LL(Node* &head){
    Node* temp=head;
    Node* Temp=head; // to get the adress of last node;
    if(temp==NULL){
        cout<<"LL is empty\n";
    }
    while(Temp->next!=head){
        Temp=Temp->next;
    }
    Node* prev=Temp;
    Node* next=NULL;
    while(temp->next!=head){
        next=temp->next; // stores the adress of next block
        temp->next=prev;
        prev=temp; // stores the adress of current block
        temp=next;
    }
    temp->next=prev;
    head=temp; // head will now point to the last node
    

}

void count(Node* head){
    int cnt=0;
    Node* temp=head;
    if(temp==NULL){
        cout<<"Number of nodes present are --> "<<cnt<<endl;
    }else{
        do{   
            cnt+=1;
            temp=temp->next;
        }while(temp!=head);
        cout<<"Number of nodes present are --> "<<cnt<<endl;
    }
}
int main(){
    Node* head=NULL;
    insertatBeg(head,5);
    print(head);
    insertatBeg(head,4);
    print(head);
    insertatEnd(head,3);
    print(head);
    insertatIndex(head,0,10);
    insertatIndex(head,4,20);
    deleteatIndex(head,0);
    deleteatIndex(head,2);
    deleteatIndex(head,1);
    insertatIndex(head,2,6);
    reverse_circular_LL(head);
    print(head);

}