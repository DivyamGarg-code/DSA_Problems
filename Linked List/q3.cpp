// Taking input from the user
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
    Node *head=NULL; 
    while(data!=-1){
        Node *newnode=new Node(data); // storing the data at this node --> [data,NULL] here newnode act as a head
        if(head==NULL){
            head=newnode; // head basically stores the address of 1st node
        }else{
            Node *temp=head;
            while(temp->next!=NULL){ // this will traverse until I get the last inserted node [data,NULL]
                temp=temp->next;
            }
            temp->next=newnode; //  and then we can store the address of newnode in the previous node
        }
        cin>>data;
    }
    return head;
}    
// Best Case O(1)
// Worst case O(n)
// Avg case sum of all cases/total number of cases (1+2+3+....+n)/n ->(n+1)/2
void linear_search(int a[],int key,int size){
    int found =0;
    int i=0;
    for(; i < size; i++){
        if(a[i]==key){
            found=1;
            break;
        }
    }
    if(found==1){
        cout<<key<<" present at index "<<i;
    }else{
        cout<<key<<" not present";
    }

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