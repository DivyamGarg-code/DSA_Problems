// Taking input from the user and start inserting elements from the end where we left the number of times we call the takeinput() function
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
Node *Temp=NULL; // giving the global declaration
Node *head=NULL;

Node* takeinput(){
    int data;
    cin>>data;
    while(data!=-1){
        Node *newnode=new Node(data); // storing the data at this node --> [data,NULL] here newnode act as a head
        if(head==NULL){
            head=newnode; // head basically stores the address of 1st node
            Temp=head;
        }else{ // when their is more than 1 element
            Temp->next=newnode; //  and then we can store the address of newnode in the previous node
            Temp=newnode;
        }
        cin>>data;
    }
    //Temp=NULL; // the work of my temp pointer is now finished
    return head;
}
void print(Node* head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" "; // print data at this address 
        temp=temp->next; // store address of next node stored in the next pointer block at this address
    }
    cout<<endl;
}

int main(){
    Node* head=takeinput();
    print(head);
    Node* Head=takeinput();
    print(Head);
    return 0;
}