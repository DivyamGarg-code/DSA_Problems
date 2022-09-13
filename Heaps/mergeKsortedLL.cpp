#include<bits/stdc++.h>
using namespace std;

// MERGE K SORTED LL
// TC O(N*K LOG(K))
// SC O(K)
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
    cin>>data;
    char ch;
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
    if(temp==NULL){
        return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

int main(){
    int k;
    cin>>k;
    vector<Node*> v;
    for(int i=0;i<k;i++){
        Node* head=takeInput();
        v.push_back(head);

    }
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    // created the min heap
    for(int i=0;i<k;i++){
        minHeap.push(v[i]);
    }
    Node* head=NULL;
    Node* tail=NULL;
    while(minHeap.size()>0){
        Node* temp=minHeap.top();
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }
        minHeap.pop();
        if(temp->next!=NULL){
            minHeap.push(temp->next);
        }

    }
    print(head);
    return 0;
}