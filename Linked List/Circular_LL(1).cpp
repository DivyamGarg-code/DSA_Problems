#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            next=NULL;
        }
};

Node* takeInput(){
    Node* head=NULL;
    Node* tail=NULL;
    int data;
    char ch;
    ch='1';
    cin>>data;
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
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}
void insertatBeg(Node* &head,int data){
    Node* temp=head;
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
        head->next=head;
    }else{
        while(temp->next!=head){
            temp=temp->next;
        }
        n->next=head;
        head=n;
        temp->next=n;
    }
}
void insertatEnd(Node* &head,int data){
    Node* temp=head;
    Node* n=new Node(data);
    if(head==NULL){
        head=n;
        head->next=head;
    }else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
    }
}
void insertatIndex(Node* &head,int data,int idx){
    Node* temp=head;
    int cnt=0;
    Node* n=new Node(data);
    if(idx==0){
        insertatBeg(head,data);
    }else{
        while(temp->next!=head){
            if(cnt==idx-1){
                n->next=temp->next;
                temp->next=n;
                break;
            }else{
                cnt+=1;
                temp=temp->next;
            }
        }
        if(temp->next==head && cnt==idx-1){
            temp->next=n;
            n->next=head;
        }
    }
}
void deleteatBeg(Node* &head){
    Node* temp=head;
    Node* a=temp;
    if(temp==NULL){
        cout<<"List is empty\n";
        return;
    }else{
        if(temp->next==head){
            head=NULL;
        }else{
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=head->next;
            head=head->next;
            
        }
        delete a;
    }
}
void deleteatEnd(Node* &head){
    Node* temp=head;
    Node* a=NULL;
    if(temp==NULL){
        cout<<"List is empty\n";
    }else if(temp->next==head){
        a=temp;
        head=NULL;
    }else{
        while(temp->next->next!=head){
            temp=temp->next;
        }
        a=temp->next;
        temp->next=head;
    }
    delete a;
}

void deleteatIndex(Node* &head,int idx){
    Node* temp=head;
    Node* a=NULL;
    int cnt=0;
    if(idx==0){
        deleteatBeg(head);
    }else{
        while(temp->next->next!=head){
            if(cnt==idx-1){
                a=temp->next;
                temp->next=temp->next->next;
                break;
            }else{
                cnt+=1;
                temp=temp->next;
            }
        }
        if(temp->next->next==head && cnt==idx-1){
            a=temp->next;
            temp->next=head;
        }
        delete a;
    }
}
int main(){
    Node* head=NULL;
    insertatBeg(head,5);
    print(head);
    insertatBeg(head,4);
    print(head);
    insertatEnd(head,3);
    print(head);
    deleteatIndex(head,2);
    print(head);
}