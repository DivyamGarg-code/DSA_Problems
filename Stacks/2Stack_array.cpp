#include<bits/stdc++.h>
using namespace std;

class Stack{
        
    public:
        int* arr;
        int size,top1,top2;
        Stack(int n=5){
            size=n;
            arr=new int[n];
            top1=-1;
            top2=size;
        }
        void push1(int data){
            if(top1+1!=top2){
                top1++;
                if(top1!=size){
                    arr[top1]=data;
                }else{
                    cout<<"Stack is full\n";
                }
                
            }else{
                cout<<"Stack is full\n";
            }
        }
        void push2(int data){
            if(top2-1!=top1){
                top2--;
                if(top2!=-1){
                    arr[top2]=data;
                }else{
                    cout<<"Stack is full\n";
                }
                
            }else{
                cout<<"Stack is full\n";
            }
        }
        void pop1(){
            if(top1==-1){
                cout<<"Stack is empty\n";
            }else{
                top1--;
            }
        }
        void pop2(){
            if(top2==size){
                cout<<"Stack is empty\n";
            }else{
                top2++;
            }
        }
        int Top1(){
            return arr[top1];
        }
        int Top2(){
            return arr[top2];
        }
        int empty1(){
            return top1==-1;
        }
        int empty2(){
            return top2==size;
        }
};
int main(){
    Stack s(10);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    
    s.push2(7);
    s.push2(8);
    s.push2(9);
    s.push2(10);
    s.push2(11);
    s.push2(12);
    s.push2(13);

    while(!s.empty1()){
        cout<<s.Top1()<<endl;
        s.pop1();
    }
    cout<<endl;
    while(!s.empty2()){
        cout<<s.Top2()<<endl;
        s.pop2();
    }
    return 0;
}