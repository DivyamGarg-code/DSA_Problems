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
Node* insertNode(Node* head,int index,int d){
    Node *n=new Node(d); // node to be inserted
    Node *temp=head; // conains the adress of 1st block (tail)
    int cnt=0;
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
    return head;    
}

Node* deleteNode(Node* head,int index){ //  i_th index at which you want to delete
    Node* temp=head;
    int cnt=0;
    Node* a=NULL;
    while(temp!=NULL){
        if(cnt==index && index==0){ // deleting at the index 0
            Node* a=temp;
            head=temp->next; // head now point to the 2nd node
            break;
        }else if(cnt==index-1 && index!=0){
            Node* a=temp->next;
            temp->next=temp->next->next;
            break;
        }else{
            cnt+=1;
            temp=temp->next;
        }
    }
    delete a;
    return head;
    
}

void print(Node* head){
    Node* Temp=head;
    int cnt=0;
    while(Temp!=NULL){
        cnt+=1;
        cout<<Temp->data<<" "; // print data at this address 
        Temp=Temp->next; // store address of next node stored in the next pointer block at this address
    }
    cout<<endl;
    cout<<"Number of Nodes --> "<<cnt<<endl;
}

int main(){
    int t;
    cout<<"Enter number of times do you want to perform operations : ";
    cin>>t;
    Node* head=takeinput();
    while(t>0){
        int i,d;
        cout<<"Enter at which index you want to insert element : ";
        cin>>i;
        cout<<"Enter the element that you want to insert at index "<<i<<" : ";
        cin>>d;
        head=insertNode(head,i,d); // return the adress of 1st node (will be updated if new node is inserted at the begining)
        cout<<"After inserting node\n";
        print(head);
        cout<<"Enter at which index do you want to delete element : ";
        cin>>i;
        cout<<"After deleting node\n";
        head=deleteNode(head,i); // return the adress of 1st node after deletion(will be updated if node is deleted at the begining)
        print(head);
        cout<<endl;
        t--;
    }
    return 0;
}