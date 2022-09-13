#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        int data;
        Node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }

};

Node* takeInput(){
    
}
int main(){
    Node* root=takeInput();
    return 0;
}