// Insertion and Deletion at the begining ,in b/w and at the end of the node 
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
    Node* Temp=head;
    while(Temp!=NULL){
        cout<<Temp->data<<" "; // print data at this address 
        Temp=Temp->next; // store address of next node stored in the next pointer block at this address
    }
    cout<<endl;
}

int count(Node* temp){
    if(temp==NULL){
        return 0;
    }
    return 1+count(temp->next);
}
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
            tail->next=newnode;
            tail=tail->next; // or tail=next node

        }
        cin>>data;
    }
    return head;
}
void insertatBeg(Node* &head,int data){
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
    }else{
        n->next=head;
        head=n;
    }
    
}
void insertatEnd(Node* &head,int data){
    Node* temp=head;
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
}

void insertatIndex(Node* &head,int data,int idx){
    Node* temp=head;
    int cnt=0;
    if(idx==0){
        insertatBeg(head,data);
    }else{
        while(temp!=NULL){
            if(cnt==idx-1){
                Node* n=new Node(data);
                n->next=temp->next;
                temp->next=n;
                return;
            }else{
                cnt++;
                temp=temp->next;
            }
        }
        cout<<"Index out of range\n";
    }
}

void deleteatBeg(Node* &head){
    if(head==NULL){
        cout<<"LL is empty\n";
    }else{
        Node* a=head;
        head=head->next;
        delete a;
    }
}
void deleteatEnd(Node* &head){
    Node* temp=head;
    Node* a=NULL;
    if(head==NULL){
        cout<<"LL is empty Can't delete further\n";
    }else{
        if(temp->next==NULL){
            a=head;
            head=NULL;
        }else{
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            a=temp->next;
            temp->next=NULL;
        }
    }
    delete a;
    print(head);
}

void deleteatIndex(Node* &head,int idx){
    int cnt=0;
    Node* a=NULL;
    Node* temp=head;
    if(idx==0){
        if(head!=NULL){
            a=head;
            head=head->next;
        }
    }else{
        while(temp!=NULL){
            if(cnt==idx-1){
                a=temp->next;
                temp->next=a->next;
                break;
            }else{
                cnt++;
                temp=temp->next;
            }
        }
    }
    delete a;
}

bool search(Node* head,int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }else{
        return search(head->next,key);
    }
    
}



int main(){
    Node* head=NULL;
    insertatIndex(head,10,0);
    print(head);
    insertatIndex(head,30,0);
    print(head);
    cout<<"Count is "<<count(head);
    return 0;
}