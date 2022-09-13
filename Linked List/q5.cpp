// To access the i th element
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
void print(Node* head,int index){
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        if(cnt==index){
            cout<<temp->data;
            break;
        }else{
            cnt+=1;
            temp=temp->next; // store address of next node which is stored in the [next] block at this address
        }
    }
    if(cnt!=index){
        cout<<"Index out of range\n";
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        Node* head=takeinput();
        int i;
        cin>>i;
        print(head,i);
        cout<<endl;
        t--;
    }
    return 0;
}