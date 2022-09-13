#include <bits/stdc++.h>
using namespace std;
class Stack{
    public:
        int n;
        int top=-1;
        Stack(int size){
            n=size; 
        }
        int* a=new int[n]; // dynamically memory allocation
        int isEmpty(void);
        void push(int);
        int pop();
};
int Stack::isEmpty(void){
    if(top==-1){
        return 1;
    }
    return 0;
}
void Stack::push(int data){
    if(top==n-1){
        cout<<"Stack is full\n";
        return;
    }
    top+=1;
    a[top]=data;
}
int Stack::pop(void){
    if(isEmpty()){
        cout<<"Stack is empty\n";
        return 0;
    }
    top=top-1;
    return a[top+1];
}

char character(int data){ 
    char c;
    if(data==5){
        c='^';
    }else if(data==4){
        c='*';
    }else if(data==3){
        c='/';
    }else if(data==2){
        c='+';
    }else if(data==1){
        c='-';
    }
    return c;
}
int main(){
    cout<<"Enter an infix expression\n";
    string s;
    cin>>s;
    int n=s.length();
    char* result=new char[n]; // final postfix expression
    int cnt=0; 
    Stack x(n);
    for(int i=0;s[i]!='\0';i++){
        if((int(s[i])>=48 && int(s[i])<=57) || (int(s[i])>=65 && int(s[i])<=90) || (int(s[i])>=97 && int(s[i])<=122)){ // for operand
            result[cnt]=s[i];
            cout<<s[i]<<endl;
            cnt+=1;
        }else if((int(s[i])>=40 && int(s[i])<=43) || int(s[i])==45 || int(s[i])==47 || int(s[i])==94 ){ // for operators () ^ * / + -
            if(x.isEmpty()){
                if(s[i]==')'){
                    cout<<"Enter right expression\n";
                    break;
                }else{
                    if(s[i]=='('){
                        x.push(6);
                    }else if(s[i]=='^'){
                        x.push(5);
                    }else if(s[i]=='*'){
                        x.push(4);
                    }else if(s[i]=='/'){
                        x.push(3);
                    }else if(s[i]=='+'){
                        x.push(2);
                    }else if(s[i]=='-'){
                        x.push(1);
                    }
                }
            }else{
                if(s[i]=='('){
                    x.push(6);
                }else if(s[i]=='^'){
                    if(5>=x.a[x.top] || x.a[x.top]==6 ){ // x.a[x.top] will give you the topmost element in the stack
                        x.push(5);
                    }else{
                        while(x.isEmpty()!=1 && 5<x.a[x.top] && x.a[x.top]!=6){
                            result[cnt]=character(x.pop());
                            cnt+=1;
                        }
                        if(x.a[x.top]==6){
                            x.top+=1; // this will decrement the top so that operator could be added in place of (
                            x.push(5);
                        }else{
                            x.push(5);
                        }
                    }
                }else if(s[i]=='*'){
                    if((4>x.a[x.top] || x.a[x.top]==6) && x.a[x.top]!=3){ // x.a[x.top] will give you the topmost element in the stack
                        x.push(4);
                    }else{
                        while(x.isEmpty()!=1 && (4<=x.a[x.top] || x.a[x.top]==3) && x.a[x.top]!=6){
                            result[cnt]=character(x.pop());
                            cnt+=1;
                        }
                        if(x.a[x.top]==6){
                            x.top+=1; // this will decrement the top so that operator could be added in place of (
                            x.push(4);
                        }else{
                            x.push(4);
                        }
                    }
                }else if(s[i]=='/'){
                    if(3>x.a[x.top] || x.a[x.top]==6){ // x.a[x.top] will give you the topmost element in the stack
                        x.push(3);
                    }else{
                        while(x.isEmpty()!=1 && 3<=x.a[x.top] && x.a[x.top]!=6){
                            result[cnt]=character(x.pop());
                            cnt+=1;
                        }
                        if(x.a[x.top]==6){
                            x.top+=1; // this will decrement the top so that operator could be added in place of (
                            x.push(3);
                        }else{
                            x.push(3);
                        }
                    }
                }else if(s[i]=='+'){
                    if((2>x.a[x.top] || x.a[x.top]==6) && x.a[x.top]!=1){ // x.a[x.top] will give you the topmost element in the stack
                        x.push(2);
                    }else{
                        while(x.isEmpty()!=1 && (2<=x.a[x.top] || x.a[x.top]==1) && x.a[x.top]!=6){
                            result[cnt]=character(x.pop());
                            cnt+=1;
                        }
                        if(x.a[x.top]==6){
                            x.top+=1; // this will decrement the top so that operator could be added in place of (
                            x.push(2);
                        }else{
                            x.push(2);
                        }
                    }
                }else if(s[i]=='-'){
                    if(1>x.a[x.top] || x.a[x.top]==6){ // x.a[x.top] will give you the topmost element in the stack
                        x.push(1);
                    }else{
                        while(x.isEmpty()!=1 && 1<=x.a[x.top] && x.a[x.top]!=6){
                            result[cnt]=character(x.pop());
                            cnt+=1;
                        }
                        if(x.a[x.top]==6){
                            x.top+=1; // this will decrement the top so that operator could be added in place of (
                            x.push(1);
                        }else{
                            x.push(1);
                        }
                    }
                }else if(s[i]==')'){
                    while(x.a[x.top]!=6){
                        if(x.isEmpty()){
                            cout<<"Enter correct expression\n";
                            return 0;
                        }
                        result[cnt]=character(x.pop());
                            cnt+=1;
                    }
                    x.top-=1;
                }
            }
        }
    }
    while(x.isEmpty()!=1){
        result[cnt]=character(x.pop());
        cnt+=1;
    }
    for (int i = 0; i < cnt; i++){
        cout<<result[i];
    }  
}