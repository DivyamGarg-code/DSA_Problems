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
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" "; // print data at this address 
        temp=temp->next; // store address of next node stored in the next pointer block at this address
    }
    cout<<endl;
}

int main(){
    // Dynamically alocating node values
    // n1,n2,n3,n4,n5 can be considered as the individual heads
    Node* n1=new Node(10); // n1 is the node pointer(head) containing the address of this node
    Node* n2=new Node(20); // n2 is the node pointer(head) containing the address of this node
    Node* n3=new Node(30); // n3 is the node pointer(head) containing the address of this node
    Node* n4=new Node(40); // n4 is the node pointer(head) containing the address of this node
    Node* n5=new Node(50); // n5 is the node pointer(head) containing the address of this node
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    cout<<n1->next->next<<endl;
    print(n1); // 10 20 30 40 50 
    print(n2); // 20 30 40 50 
    print(n3); // 30 40 50 
    print(n4); // 40 50 
    print(n5); // 50 
    return 0;
}