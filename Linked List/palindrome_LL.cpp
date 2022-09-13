// Palindromic LL
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
    temp=temp->next;
    return 1+count(temp);
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
Node* middle(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL){
        fast=fast->next->next;
        if(fast==NULL){
            return slow;
        }
        slow=slow->next;
    }
    return slow;
}
Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    head=prev;
    return head;
}
// void removeDuplicate(Node* &head){
//     Node* temp=head;
//     while(temp!=NULL){
//         if(temp->next==NULL){
//             break;
//         }else if(temp->data==temp->next->data){
//             Node* a=temp->next;
//             temp->next=temp->next->next; // store the adress of next block
//             delete a;
//             continue;
//         }else{
//             temp=temp->next;
//         }
//     }
//     print(head);
// }

// Approach 1 : store the elements of LL in vector(array) and compare
// TC O(N) SC O(N)
bool isPalindrome(Node* head){
    Node* temp=head;
    vector<int> v;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }
    int n=v.size();
    if(n==0){
        return true;
    }else{
        for(int i = 0; i < n/2; i++){
            if(v[i]!=v[n-i-1]){
                return false;
            }
        }
        return true;
    }
}

/* Approach 2: 
    Find the mid and reverse the LL after mid
    Take 2 pointers head and mid->next and compare till end
    Now again reverse the LL after the mid to have its correct originality
    TC O(N) SC O(1)
*/
bool checkPalindrome(Node *head){
    Node * h1=head;
    Node* h3=middle(head);
    Node* h2=reverse(h3->next);
    Node* temp=h2;
    while(h2!=NULL){
        if(h1->data!=h2->data){
            return false;
        }else{
            h1=h1->next;
            h2=h2->next;
        }
        
    }
    temp=reverse(temp);
    h3->next=temp;
    return true;
}
int main(){
    Node* head=takeinput();
    if(isPalindrome(head)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    //cout<<"Count is "<<count(head);
    return 0;
}