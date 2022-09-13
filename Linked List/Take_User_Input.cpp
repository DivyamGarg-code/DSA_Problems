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
    if(temp==NULL){
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    cout<<"Enter as many elements you want to store \n";
    Node* head=takeInput();
    print(head);
    return 0;
}