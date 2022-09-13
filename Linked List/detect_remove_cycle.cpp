// FLOYD'S CYCLE (CYCLE DETECTION AND REMOVAL)
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

bool detectCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL){
        if(fast==slow && fast!=head){
            return true;
        }
        fast=fast->next->next;
        if(fast==NULL){
            break;
        }
        slow=slow->next;
    }
    return false;
}

Node* removeCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    int cnt=0;
    int k=1;
    while(fast->next!=NULL && fast!=NULL){
        if(fast==slow && fast!=head && cnt==0){
            cnt+=1;
        }
        if(cnt==1){
            prev=fast;
            fast=fast->next;
            if(k==1){
                slow=head;
                k=0;
            }
        }else{
            fast=fast->next->next;
        }
        slow=slow->next;
        if(fast==slow && fast!=head && cnt==1){
            prev->next=NULL;
            break;
        }
    }
    return head;
}
Node* last_element(Node* head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}
int main(){
    Node* head=takeInput();
    Node* n1=last_element(head);
    n1->next=head->next->next;
    // print(head);
    print(removeCycle(head));
    return 0;
}