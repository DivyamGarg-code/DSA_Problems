#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

Node* takeInput(){
    Node* head=NULL;
    Node* temp=NULL;
    int data;
    char c=' ';
    cin>>data;
    while(1){
        Node* n=new Node(data);
        if(head==NULL){
            head=n;
            temp=n;
        }else{
            temp->next=n;
            temp=n;
        }
        c=cin.get();
        if(c=='\n'){
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

Node* merge(Node* h1,Node* h2){
    Node* h3=NULL;
    Node* t3=NULL;
    while(h1!=NULL && h2!=NULL){
        if(h3==NULL){
            if(h1->data<h2->data){
                h3=h1;
                t3=h1;
                h1=h1->next;
            }else{
                h3=h2;
                t3=h2;
                h2=h2->next;
            }
        }else{
           if(h1->data<h2->data){
                t3->next=h1;
                t3=h1;
                h1=h1->next;
            }else{
                t3->next=h2;
                t3=h2;
                h2=h2->next;
            } 
        }
    }
    while(h1!=NULL){
        t3->next=h1;
        t3=h1;
        h1=h1->next;
    }
    while(h2!=NULL){
        t3->next=h2;
        t3=h2;
        h2=h2->next;
    }
    return h3;
}
Node* midpoint(Node* head){ // will return the mid-point 
    Node* h2=NULL;
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL){
        fast=fast->next->next;
        if(fast==NULL){ // For even case;
            return slow;
        }
        slow=slow->next;
    }
    return slow;

}
// Overall TC will be O(nlog(n))
Node* merge_sort(Node* head){
    // Base Case
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* mid=midpoint(head); // will return the mid point
    Node* h1=head; // First half
    Node* h2=mid->next; // 2nd half
    mid->next=NULL; // Breaking the LL

    // Rec solve the 2 parts
    h1=merge_sort(h1);  // Calling merge sort on First half
    h2=merge_sort(h2); // Calling merge sort on 2nd half

    // merge them
    Node* h3=merge(h1,h2);
    return h3;
}
int main(){
    Node* head=takeInput();
    // Node* h2=takeInput();
    // merge(h1,h2);
    head=merge_sort(head);
    print(head);

    return 0;
}