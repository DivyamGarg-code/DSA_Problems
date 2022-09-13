// Recursively insertion and deletion of LL
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this->data=data;
        }
};

Node* takeInput(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* temp=NULL;
    char ch='1';
    while(1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
        ch=cin.get();
        if(ch=='\n'){
            break;
        }
        cin>>data;
        
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insertNodeRec(Node* head,int data,int i){
    if(head==NULL && i!=0){
        return head;
    }
    if(i<=0){
        Node* n=new Node(data);
        n->next=head;
        head=n;
        return head;
    }
    Node* temp=insertNodeRec(head->next,data,i-1);
    head->next=temp;
    return head;

}

Node* deleteNodeRec(Node* head,int i){
    if(head==NULL && i!=0){
        return head;
    }
    if(i<=0){
        Node* n=head->next;
        Node* a=head;
        delete a;
        return n;
    }
    Node* temp=deleteNodeRec(head->next,i-1);
    head->next=temp;//connecting the previous node with the next node of the deleted node
    return head;

}
int main(){
    Node* head=takeInput();
    print(deleteNodeRec(head,1));
    return 0;
}