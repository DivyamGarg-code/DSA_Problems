/*Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
Sample Input 1 :
1 2 3 4 5 6 7 8 9 10
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
*/
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
int cnt(Node* head){
    if(head==NULL){
        return 0;
    }
    return 1+cnt(head->next);
}
// 1 2 3 4  5 6 7 8 9 10
vector<Node*> reverse(Node* head,int n){
    vector<Node*> v;
    int i=0;
    v.push_back(head);
    Node* prev=NULL;
    Node* next=NULL;
    Node* temp=head;
    while(temp!=NULL && i<n){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
        i++;
    }
    head=prev;
    v.push_back(next);
    v.push_back(head);
    return v;

}

Node* kReverse(Node* head,int n){
    if(head==NULL || n==1 || n==0){
        return head;
    }
    Node* Head=NULL;
    Node* curr_head=NULL;
    Node* temp1;
    Node* prev1;
    Node* temp2;
    Node* prev2;
    int N=cnt(head)/n +1;
    int i=1;
    vector<Node*> v=reverse(head,n);
    prev1=v[0];
    prev2=v[1];
    curr_head=v[2];
    Head=curr_head;
    head=prev2;
    i++;
    while(i<=N){
        vector<Node*> v=reverse(head,n);
        temp1=v[0];
        temp2=v[1];
        curr_head=v[2];
        head=temp2;
        prev1->next=curr_head;
        prev1=temp1;
        i++;
    }
    return Head;
}
int main(){
    Node* head=takeInput();
    int n;
    cin>>n;
    print(kReverse(head,n));
}