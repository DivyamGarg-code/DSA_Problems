#include<bits/stdc++.h>
using namespace std;
// push() pop() top() empty() operations work in O(1) time
// template<typename T,typename U>
template<typename T>
class Stack{
    private:
        vector<T> v;
        // vector<U> x; If you want to create a vector of another data type
    public:
        bool empty(){
            return v.size()==0;
        }
        void push(T data){
            v.push_back(data);
        }
        void pop(){
            if(!empty()){
                v.pop_back();
            }
        }
        T top(){
            return v[v.size()-1];
        }
};
int main(){
    Stack<int> s;
    for(int i=0;i<5;i++){
        s.push(i*i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}