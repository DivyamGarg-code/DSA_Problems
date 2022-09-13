#include<bits/stdc++.h>
using namespace std;
//  IMPORTANT
// Rehashing is done to minimize the collisions.though it is an expensive operation but still useful
// To avoid the frequent rehash the initial size of the table should be kept high suchh that load factor<0.7
template<typename T>
class Node{
    public:
        string key;
        T value;
        Node<T>* next;
        Node(string key,T data){
            this->key=key;
            value=data;
            next=NULL;
        }
        ~Node(){
            if(next!=NULL){
                delete next;
            }
        }
};

template<typename T>
class Hashmap{
    int curr_size;
    int table_size;
    Node<T>** table;
    int hashf(string key){
        int idx=0;
        int p=1;
        for(int i=0;i<key.length();i++){
            idx=idx+(key[i]*p)%table_size;
            idx=idx%table_size;
            p=(p*27)%table_size;
        }
        return idx;
    }
    void rehash(){
        Node<T>** oldTable=table;
        int oldTableSize=table_size;
        table_size=2*table_size; // approximation find the next prime number
        table=new Node<T>*[table_size];
        for(int i=0;i<table_size;i++){
            table[i]=NULL;
        }
        curr_size=0;
        // now we will shift the elements from old table to new table
        for(int i=0;i<oldTableSize;i++){
            Node<T>* temp=oldTable[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp=temp->next;
            }
            if(oldTable[i]!=NULL){ // clear the entries of the old table
                delete oldTable[i];
            }
        }
        delete [] oldTable; // clear the old table
    }
    public:
        Hashmap(int ms=7){
            table_size=ms;
            table=new Node<T>*[table_size];// create a table array
            for(int i=0;i<table_size;i++){
                table[i]=NULL;
            }
        }
        void insert(string key,T data){
            int idx=hashf(key);
            Node<T>* temp=new Node<T>(key,data);
            temp->next=table[idx];
            table[idx]=temp;
            curr_size++;
            // rehashing
            float load_factor=curr_size/(1.0*table_size);
            if(load_factor>0.7){
                rehash();
            }
        }
        void print(){
            for(int i=0;i<table_size;i++){
                Node<T>* temp=table[i];
                cout<<"index "<<i<<" -> ";
                while(temp!=NULL){
                    cout<<temp->key<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
};

int main(){
    Hashmap<int> price_menu;
    price_menu.insert("Burger",120);
    price_menu.insert("Pepsi",20);
    price_menu.insert("BurgerPizza",150);
    price_menu.insert("Noodles",25);
    price_menu.insert("Coke",40);
    price_menu.print();
    return 0;
}