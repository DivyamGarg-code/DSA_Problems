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

// Iterative approach is more efficient as it is taking O(n) time and O(1) space
Node* reverse_singly_LL(Node* &head){ 
    Node* temp=head;
    Node* prev=NULL;
    Node* next=NULL; // 
    if(temp==NULL){
        cout<<"LL is empty\n";
    }
    while(temp!=NULL){
        next=temp->next; // stores the adress of next node so that we can continue moving after the broken link and update the temp pointer afterwards
        temp->next=prev; // stores the adress of prevous node
        prev=temp; // stores the adress of current node
        temp=next;
    }
    head=prev;
    return head;
}

Node* recReverse(Node* head){ // O(n^2)
    // Base Case
    if(head->next==NULL || head==NULL){
        return head;
    }
    Node* shead=recReverse(head->next); // Assumed ke reversed smaller LL ka head la kr dega
    Node* temp=shead;
    while(temp->next!=NULL){ // going reverse to get the 2nd last node
        temp=temp->next;
    }
    head->next=NULL;
    temp->next=head;
    return shead;
}
// The TC will be O(n)time : O(n) stack space
Node* recReverse(Node* head){ // O(n)-> optimized
    // Base Case
    if(head->next==NULL || head==NULL){
        return head;
    }
    Node* shead=recReverse(head->next); // Assumed ke reversed smaller LL ka head la kr dega
    Node* temp=head->next; // 2nd last node
    temp->next=head;
    head->next=NULL;
    return shead;
}
void print(Node* head){
    int len=0;
    Node* temp=head;
    if(temp==NULL){
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        len+=1; // If you want to count the length of LL
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=takeInput();
    // reverse_singly_LL(head);
    print(recReverse(head));
    return 0;
}