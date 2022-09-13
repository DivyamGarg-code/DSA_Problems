// ANOTHER GREAT METHOD OF
// Insertion AND DELETION at the begining ,in b/w and at the end of the node "SPECIAL CASE" in you can insert multiple times and update the same list
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
            // Node *temp=head;
            // while(temp->next!=NULL){ // this will traverse until I get the last inserted node [data,NULL]
            //     temp=temp->next;
            // }
            // temp->next=newnode; //  and then we can store the address of newnode in the previous node
            // To reduce the time complexity from O(n^2) to O(n)
            tail->next=newnode;
            tail=tail->next; // or tail=next node

        }
        cin>>data;
    }
    return head;
}
Node* insertNode(Node* head,int index,int d){
    Node *n=new Node(d);
    Node *temp=head; // conains the adress of 1st block (tail)
    Node *Temp=head; // for updating the head if 1st block is pointed (head)
    int cnt=0;
    while(temp!=NULL){
        if(cnt==index && index==0){ // insertion at the begining
            n->next=temp; // ie the new inserted node at 1st position will contain the address of next node
            Temp=n; // head now point to the new inserted element
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
    return Temp;    
}

Node* deleteNode(Node* head,int index){ // i --> i_th index at which i want to delete
    Node* tail=head;
    Node* temp=head;
    int cnt=0;
    while(tail!=NULL){
        if(cnt==index && index==0){ // deleting at the index 0
            temp=temp->next;
            break;
        }else if(cnt==index-1 && index!=0){
            tail->next=tail->next->next;
            break;
        }else{
            cnt+=1;
            tail=tail->next;
        }
    }
    return temp;
    
}

void print(Node* head){
    Node* Temp=head;
    while(Temp!=NULL){
        cout<<Temp->data<<" "; // print data at this address 
        Temp=Temp->next; // store address of next node stored in the next pointer block at this address
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
        Node* head=takeinput();
    while(t>0){
        int i;
        cout<<"Enter at which index you want to insert element : ";
        cin>>i;
        int d;
        cout<<"Enter the element that you want to insert at index "<<i<<" : ";
        cin>>d;
        head=insertNode(head,i,d); // return the adress of 1st node (updated if new node indserted at the begining)
        cout<<"After inserting node\n";
        print(head);
        cout<<"After deleting node\n";
        print(deleteNode(head,i));
        cout<<endl;
        t--;
    }
    return 0;
}