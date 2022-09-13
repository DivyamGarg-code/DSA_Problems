#include<bits/stdc++.h>
using namespace std;

// Easy Access Using Operation : Operator Overloading
/*
If you want to map
    Insert : price_menu["Dosa"]=60
    Update : price_menu["Dosa"]+=10
    Search : cout<<price_menu["Dosa"]
*/
template<typename T>
class Node{
    public:
        string key;
        T value;
        Node<T>* next;
        Node(string key,T val){
            this->key=key;
            value=val;
            next=NULL;
        }
        ~Node(){
            if(next!=NULL){ // Recursively delete from the head pointer to last jab tak null nhi aa jata
                delete next;
            }
        }
};

template<typename T>
class Hashtable{
    Node<T>** table; // pointer to an array of pointers
    int current_size;
    int table_size;

    int hashfn(string key){
        int idx=0;
        int p=1;
        for(int i=0;i<key.length();i++){
            idx=idx+(key[i]*p)%table_size; // 'a'*1 'a'*27 'a'*27^2....
            idx=idx%table_size;
            p=(p*27)%table_size;
        }
        return idx;
    }
    // we are doing modulo again and again in order to avoid the index overflow in case of large numbers
    public:
        Hashtable(int ts=7){
            table_size=ts;
             table=new Node<T>*[table_size]; 
             current_size=0;
             for(int i=0;i<table_size;i++){
                 table[i]=NULL;
             }
        }
        void insert(string key,T value){
            int idx=hashfn(key);
            Node<T>* n=new Node<T>(key,value); 
            // insert at the head of the LL with id=idx
            n->next=table[idx];
            table[idx]=n;
            current_size+=1;
        }

        void print(){
            for(int i=0;i<table_size;i++){
                cout<<"Table "<<i<<" -> ";
                Node<T>* temp=table[i];
                while(temp!=NULL){
                    cout<<temp->key<<" -> ";
                    temp=temp->next;
                }
                cout<<endl;
            }
            cout<<endl;
        }
        T* search(string key){
            int idx=hashfn(key);
            Node<T>* temp=table[idx];
            while(temp!=NULL){
                if(temp->key==key){
                    return &temp->value; // here we will return the adress of the pointer
                }else{
                    temp=temp->next;
                }
            }
            return NULL;
        }

        void erase(string key){
            int idx=hashfn(key);
            Node<T>* head=table[idx];
            Node<T>* tail=table[idx];
            Node<T>* prev=NULL;
            if(head->key==key){
                table[idx]=head->next;
                head->next=NULL;
                delete head;
                return;
            }
            while(tail!=NULL){
                if(tail->key==key){
                    prev->next=tail->next;
                    tail->next=NULL;
                    delete tail;
                    return;
                }else{
                    prev=tail;
                    tail=tail->next;
                }
            }
        }
        // operator overloading
        T& operator[](string key){ // very important
            T* f=search(key);
            if(f==NULL){
                // Insert the key and value(garbage) in the hashmap
                T garbage;
                insert(key,garbage);
                f=search(key);
            }
            // f is the adress of that node 
            // *f is the block containing string and int
            return *f; // you are returning the the integer block therfore we will pass it by referrence so as to get the value updated
        }// it will update the value of integer as passed by reference
        // T&*f means &value

};
int main(){
    Hashtable<int> price_menu;
    price_menu["Dosa"]=60;
    price_menu["Dosa"]+=10;
    cout<<"Price of Dosa is "<<price_menu["Dosa"];

    return 0;
}