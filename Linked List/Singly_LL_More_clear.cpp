#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next=NULL;
        Node(int data){
            this->data=data;
        }
};

// Node* takeInput(){
//     int data;
//     cin>>data;
//     Node* head=NULL;
//     Node* temp=NULL;
//     while(data!=-1){
//         Node* newnode=new Node(data);
//         if(head==NULL){
//             head=newnode;
//             temp=newnode;
//         }else{
//             temp->next=newnode;
//             temp=newnode;
//         }
//         cin>>data;
//     }
//     return head;
// }
Node* takeInput(){
    int data;
    cin>>data;
    Node* head=NULL;
    Node* temp=NULL;
    char ch='1';
    while(1){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
        ch=cin.get();
        if(ch=='\n'){
            break;
        }
        cin>>data;
        
    }
    return head;
}

void insertatBeg(Node* &head,int data){
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
}


void insertatEnd(Node* &head,int data){
    Node* temp=head;
    Node* newnode=new Node(data);
    if(head==NULL){
        head=newnode;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void insertatIndex(Node* &head, int idx,int data){
    int cnt=0;
    Node* temp=head;
    Node* newnode=new Node(data);
    if(idx==0){ // At the beginning
        insertatBeg(head,data);
        return;
    }else{
        while(temp->next!=NULL){
            if(cnt==idx-1){
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }else{
                cnt++;
                temp=temp->next;
            }
        }
        if(temp->next==NULL && cnt==idx-1){// For insertion at last
            temp->next=newnode;
        }else{
            cout<<"Enter the correct index\n";
        }
    }
}

void deleteNode(Node* &head,int idx){
    int cnt=0;
    Node* temp=head;
    Node* a=NULL;
    if(idx==0){ // deletion at begining
        if(temp==NULL){ 
            cout<<"As LL is empty, Can't delete further\n";
            return;
        }else{
            a=head;
            head=head->next;
        }
    }else{ 
        while(temp->next!=NULL){ // For deletion at i_th index
            if(cnt==idx-1){
                a=temp->next;
                temp->next=temp->next->next;
                break;
            }else{
                cnt++;
                temp=temp->next;
            }
        }
    }
    delete a;

}

void reverse_singly_LL(Node* &head){
    Node* temp=head;
    Node* prev=NULL;
    Node* next=NULL; 
    if(temp==NULL){
        cout<<"LL is empty\n";
    }
    while(temp!=NULL){
        next=temp->next; // stores the adress of next node so that we can continue moving after the broken link and update the temp pointer afterwards
        temp->next=prev; // stores the adress of prevous node
        prev=temp; // stores the adress of current node
        temp=next;
    }
    head=prev;
}

void swap_k_th_element(Node* &head,int k){ // swaping k_th and k+1_th element
    Node* temp=head;
    int cnt=0;
    int idx=k-1;
    if(temp==NULL){
        cout<<"Swaping is not possible\n";
        return;
    }
    while(temp!=NULL){
        if(cnt==idx){
            if(temp->next!=NULL){ // for swapping
                int t=temp->data;
                temp->data=temp->next->data;
                temp->next->data=t;
                return;
            }else{
                cout<<"Swaping is not possible\n";
            }
        }else{
            cnt++;
            temp=temp->next;
        }
    }
    cout<<"Swaping is not possible\n";

}

int count(Node* head){
    int cnt=0;
    Node*temp=head;
    if(temp==NULL){
        return 0;
    }
    return 1+count(temp->next);
}

// Swap two Nodes of LL
void swapLL(Node* &head,int a,int b){
    Node* temp=head;
    int idx=0;
    int i=min(a,b); // smaller index
    int j=max(a,b); // larger index
    int n=count(head);
    if((i>=0 && i<n) && (j>=0 && j<n) && i!=j){
        Node* temp1=NULL; // adress of i
        Node* prev1=NULL; // adress of prev node 
        Node* temp2=NULL; // adress of j
        Node* prev2=NULL; // adress of prev node 
        while(temp!=NULL){
            if(i==idx && i==0){
                temp1=temp;
            }
            if(idx==i-1){
                prev1=temp;
                temp1=prev1->next;
            }
            if(idx==j-1){
                prev2=temp;
                temp2=prev2->next;
                break;
            }
            idx+=1;
            temp=temp->next;
        }
        if(i==0){
            if(j==1){
               head=temp2;
               temp1->next=temp2->next;
               temp2->next=temp1; 
            }else{
                Node* p=temp2->next;
                head=temp2;
                temp2->next=temp1->next;
                temp1->next=p;
                prev2->next=temp1;
            }
        }else{
            if(j==i+1){
                Node* p2=temp2->next;
                temp1->next=p2;
                temp2->next=temp1;
                prev1->next=temp2;
            }else{
                Node* p1=temp1->next;
                Node* p2=temp2->next;
                temp1->next=p2;
                prev2->next=temp1;

                temp2->next=p1;
                prev1->next=temp2;

                
            }

        }
    }
    print(head);
}

void middle_element(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL){
        fast=fast->next->next; // increment by 2 times total iterations decreased by half
        if(fast==NULL){ // for even case
            cout<<"middle element will be "<<slow->data<<" and "<<slow->next->data;
            return;
        }
        slow=slow->next;
    }
    cout<<"middle element will be "<<slow->data; // odd case
}

int max_element(Node* head){ // return the index of maximum element
    int cnt=0;
    int idx=0; // return the index of maximum element
    Node* temp=head;
    if(temp==NULL){
        return -1;
    }
    int max=head->data; 
    temp=temp->next;
    cnt+=1;
    while(temp!=NULL){
        if(max<temp->data){
            max=temp->data;
            idx=cnt;
        }
        temp=temp->next;
        cnt++;
    }
    return idx;
}

int return_n_th_node(Node* head,int n){ // n is n_th node from end or (N-n+1)th node from begining
    int len=0;
    int cnt=0;
    Node* Temp=head;
    Node* temp=head;
    if(temp==NULL){
        return -1;
    }
    while(Temp!=NULL){
        len+=1;
        Temp=Temp->next;
    }
    int idx=len-n;
    while(temp!=NULL){
        if(cnt==idx){
            return temp->data;
        }
        cnt++;
        temp=temp->next;
    }
    return -1;

}
void print(Node* head){
    int len=0;
    Node* temp=head;
    if(temp==NULL){
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        len+=1; // If you want to count the length of LL
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=takeInput();
    cout<<return_n_th_node(head,7);
    return 0;
}