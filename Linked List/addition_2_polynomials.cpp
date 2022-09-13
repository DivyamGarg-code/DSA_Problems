// Addition of 2 polynomials
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        int expo;
        Node* next=NULL;
        Node(int data,int expo){
            this->data=data; // coefficient
            this->expo=expo; // exponent
        }
};
void print(Node* head){
    int cnt=1;
    int c=0;
    Node* temp=head;
    while(temp!=NULL){
        if(cnt==1){
            if(temp->data!=0){
                c=1;
                cout<<temp->data<<"x^"<<temp->expo<<" ";
            }
            cnt+=1;
        }else{
            if(temp->expo==0){
                if(temp->data>0){
                    c=1;
                    cout<<"+ "<<temp->data<<" ";
                }else if(temp->data<0){
                    c=1;
                    cout<<"- "<<abs(temp->data)<<" ";
                }
            }else{
                if(temp->data>0){
                    c=1;
                    cout<<"+ "<<temp->data<<"x^"<<temp->expo<<" ";
                }else if(temp->data<0){
                    c=1;
                    cout<<"- "<<abs(temp->data)<<"x^"<<temp->expo<<" ";
                }
            }
        }
        temp=temp->next; // store address of next node stored in the next pointer block at this address
    }
    if(c==0){
        cout<<0;
    }
    cout<<endl;
}

int count(Node* temp){
    if(temp==NULL){
        return 0;
    }
    temp=temp->next;
    return 1+count(temp);
}
Node* takeinput(){
    int data,expo;
    cin>>data>>expo;
    Node *head=NULL; // point to the adress of 1st node
    Node *tail=NULL; // point to the adress of last node
    while(data!=-1){
        Node *newnode=new Node(data,expo); // storing the data at this node --> [data,NULL] here newnode act as a head
        if(head==NULL){
            head=newnode; // head basically stores the address of 1st node
            tail=newnode;
        }else{ 
            tail->next=newnode;
            tail=tail->next; // or tail=next node

        }
        cin>>data>>expo;
    }
    return head;
}
void insertNode(Node* &head,int index,int d,int expo){
    Node *n=new Node(d,expo); // node to be inserted
    Node *temp=head; // conains the adress of 1st block (tail) which is inside the head[...] block
    int cnt=0;
    if(temp==NULL){
        if(cnt==index && index==0){
            head=n;
        }else{
            cout<<"Enter the correct index\n";
        }
    }
    while(temp!=NULL){
        if(cnt==index && index==0){ // insertion at the begining
            n->next=temp; // ie the new inserted node at 1st position will contain the address of next node
            head=n; // head now point to the new inserted element
            break;
        }else if(cnt==index-1 && index!=0){ // insertion at the middle
            if(temp->next!=NULL){
                n->next=temp->next;
                temp->next=n;
                break;
            }else{ // insertion at the end
                temp->next=n;
                break;
            }
        }else{
            cnt+=1;
            temp=temp->next; // store address of next node stored in the next pointer block at this address
        }
    }
    print(head);
}

void deleteNode(Node* &head,int index){ //  i_th index at which you want to delete
    Node* temp=head;
    Node* a=NULL;
    int cnt=0;
    if(temp==NULL){
        cout<<"As the list is empty you cant delete further\n";
    }
    while(temp!=NULL){
        if(cnt==index && index==0){ // deleting at the index 0
            a=temp;
            head=temp->next; // head now point to the 2nd node
            break;
        }else if(cnt==index-1 && index!=0){
            a=temp->next;
            temp->next=temp->next->next;
            break;
        }else{
            cnt+=1;
            temp=temp->next;
        }
    }
    delete a;
    print(head);
}
void polynomial_addition(Node* p1,Node* p2){//passed by copy
    Node* head=NULL;
    Node* tail=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->expo==p2->expo){
            Node *n=new Node(p1->data+p2->data,p1->expo);
            if(head==NULL){
                head=n;
                tail=n;
            }else{
                tail->next=n;
                tail=n;
            }
            p1=p1->next;
            p2=p2->next;
        }else if(p1->expo>p2->expo){
            Node *n=new Node(p1->data,p1->expo);
            if(head==NULL){
                head=n;
                tail=n;
            }else{
                tail->next=n;
                tail=n;
            }
            p1=p1->next;
        }else{
            Node *n=new Node(p2->data,p2->expo);
            if(head==NULL){
                head=n;
                tail=n;
            }else{
                tail->next=n;
                tail=n;
            }
            p2=p2->next;
        }
    }
    while(p1!=NULL){
           Node *n=new Node(p1->data,p1->expo);
            if(head==NULL){
                head=n;
                tail=n;
            }else{
                tail->next=n;
                tail=n;
            }
            p1=p1->next;
        }
    while(p2!=NULL){
        Node *n=new Node(p2->data,p2->expo);
        if(head==NULL){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
        p2=p2->next;
    }
    print(head);
}

int main(){
    cout<<"Enter 1st polynomial\n";
    Node* p1=takeinput();
    cout<<"Enter 2nd polynomial\n";
    Node* p2=takeinput();
    cout<<"Polynomial 1: ";
    print(p1);
    cout<<"Polynomial 2: ";
    print(p2);
    cout<<"Their addition : ";
    polynomial_addition(p1,p2);
    return 0;
}