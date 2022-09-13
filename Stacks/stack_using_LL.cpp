#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
      //  friend class Stack;
        T data;
        Node<T>* next;
        Node(T data){
            this->data=data;
            next=NULL;
        }
};

template<typename T>
class Stack{
    public:
        Node<T>* head;
        Node<T>* temp;
        int cnt;
        Stack(){
            head=NULL;
            temp=NULL;
            cnt=0;
        }
        void push(T data){ // insert the data in the beginening
            Node<T>* n=new Node<T>(data);
            if(head==NULL){
                head=n;
                temp=n;
            }else{
                n->next=head;
                head=n;
            }
            cnt+=1;
        }
        void pop(){
            if(head!=NULL){
                Node<T>* a=head;
                head=head->next;
                cnt-=1;
                delete a;
            }
        }
        int empty(){
            if(cnt==0){
                return 1;
            }
            return 0;
        }
        int size(){
            return cnt;
        }
        T top(){
            return head->data;
        }

};

template<typename T>
void print(Stack<T> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main(){
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    cout<<s.size()<<endl;
    print(s);
    return 0;

}