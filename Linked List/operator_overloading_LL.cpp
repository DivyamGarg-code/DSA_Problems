// Operator overloading using these operators <<(cout) and >>(cin)
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

void print(Node * head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//while creating the operator : overloading you need to pass 2 objects 
// cout<< : class of ostream
// head : class of Node*
// void operator<<(ostream &os,Node* head){
//     print(head);
// }
ostream& operator<<(ostream &os,Node* head){
    print(head);
    return os; // basically return the cout<<
}

istream& operator>>(istream &is,Node* &head){
    head=takeInput();
    return is; // basically return the cout<<
}
int main(){
    Node* head1=takeInput();
    // cout<<head1; // Printing entire LL by using cout<<
    Node* head2=takeInput();
    cout<<head1<<head2;
    // Now cout<<head1 will return void due to which it will give error
    //So to avoid this we use cascading of operator
    Node* head3;
    Node* head4;
    cin>>head3>>head4;
    cout<<head3<<head4;
}