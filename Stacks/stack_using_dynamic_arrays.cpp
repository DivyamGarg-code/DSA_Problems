// Stack formed with the array of dynamic size 
// It can be formed by copying the data of original in new array made dynamically with double the size of the original array and discard the
// original.
#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
        int* a;
        int max_size;
        int top_index=-1;
    public:
        // Stack(int n){
        //     a=new int(n);
        //     max_size=n;
        // }
        int isEmpty(void);
        void print();
        void top(); // To access the topmost element
        void push(int); // insertion
        int pop(void); // deletion
        void size(void); // size of stack




};
int Stack::isEmpty(void){
    if(top_index==-1){
        return 1;
    }
    return 0;
}
void Stack::print(){
    for(int i=0;i<=top_index;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
void Stack::top(){
    if(isEmpty()){
        cout<<"Stack is Empty\n";
    }else{
        cout<<a[top_index]<<"\n";
    }
}
void Stack::push(int data){
    if(isEmpty()){
        a=new int[1];
        max_size=1;
    }else if(top_index==max_size-1){
        int* b=a;
        a=new int[2*max_size];
        for(int i=0;i<max_size;i++){
            a[i]=b[i];
        }
        max_size*=2;
        delete []b;
    }
    top_index+=1;
    a[top_index]=data;
}
int Stack::pop(){
    if(isEmpty()){
        cout<<"Stack underflow\n";
        return 0;
    }else{
        top_index-=1;
        return a[top_index+1];
    }
}
void Stack::size(){
    cout<<top_index+1<<endl;
}


int main(){
    Stack p;
    p.push(1);
    p.print();
    p.push(2);
    p.print();
    p.push(3);
    p.print();
    p.push(4);
    p.print();
    p.push(5);
    p.print();
    p.pop();
    p.print();
    p.pop();
    p.print();
    p.pop();
    p.print();
    p.pop();
    p.print();
    p.pop();
    p.print();
    p.pop();
    p.print();
    p.pop();
    p.print();
    p.top();
}