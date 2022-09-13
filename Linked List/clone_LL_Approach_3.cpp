#include<bits/stdc++.h>
using namespace std;
// Cloning a LL using random pointer
// Approach 3. Time complexity O(n)... Space Complexity O(1)
// By changing the links
// 1->2->3->4->5 
// 1->3 , 2->1 , 3->5 , 4->3 , 5->3 random pointers
class Node{
    public:
        int data;
        Node* next;
        Node* random;
        Node(int data){
            this->data=data;
            next=NULL;
            random=NULL;
        }
};

Node* takeInput(){
    Node* head=NULL;
    Node* tail=NULL;
    int data;
    cin>>data;
    char ch=' ';
    while(1){
        Node* n=new Node(data);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;
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

Node* cloneLL(Node* head){
    Node* temp=head;
    Node* h1=NULL;
    Node* h3=NULL; // final head
    Node* tail=NULL;
    while(temp!=NULL){ // creating a simple LL
        Node* n=new Node(temp->data);
        if(h1==NULL){
            h1=n;
            h3=n; // Final head
            tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
        temp=temp->next;
    }
    temp=head;
    h1=h3;
    while(temp!=NULL){ // changing the links
        Node* a=h1->next;
        h1->next=temp->next;
        temp->next=h1;
        temp=h1->next; // updating the temp
        h1=a; // updating the h1
    }
    temp=head;
    while(temp!=NULL){ // to link the random pointer in cloned LL
        if(temp->random!=NULL){
            temp->next->random=temp->random->next;
        }else{
            temp->next->random=temp->random;
        }
        temp=temp->next->next;
    }
    temp=head;
    h1=h3;
    while(temp!=NULL){ // reverting the changes done in step 2
        temp->next=h1->next;
        temp=temp->next;
        if(temp!=NULL){
            h1->next=temp->next;
            h1=h1->next;
        }else{
            h1->next=NULL;
        }
    }
    return h3;
}
int main(){
    Node* head=takeInput();
    head->random=head->next->next; // for 1
    head->next->random=head; // for 2
    head->next->next->random=head->next->next->next->next; // for 3
    head->next->next->next->random=head->next->next; // for 4
    head->next->next->next->next->random=head->next->next; // for 5

    cout<<head->random->data<<endl;
    cout<<head->next->random->data<<endl;
    cout<<head->next->next->random->data<<endl;
    cout<<head->next->next->next->random->data<<endl;
    cout<<head->next->next->next->next->random->data<<"\n\n";

    Node* h=cloneLL(head);

    cout<<h->random->data<<endl;
    cout<<h->next->random->data<<endl;
    cout<<h->next->next->random->data<<endl;
    cout<<h->next->next->next->random->data<<endl;
    cout<<h->next->next->next->next->random->data<<"\n\n";


    return 0;
}