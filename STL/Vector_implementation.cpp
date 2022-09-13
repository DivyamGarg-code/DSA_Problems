#include<bits/stdc++.h>
using namespace std;

// IMPLEMENTATION OF VECTOR CLASS
template<class T>
class Vector{
    private:
        int cs; // current size
        int ms; // maximum size
        T *arr;
    public:
        Vector(){
            cs=0;
            ms=1;
            arr=new T[ms];
        }
        void push_back(T data){
            if(cs==ms){
                // When Array is full
                T *ptr=arr;
                arr=new T[2*ms];
                ms*=2;
                for(int i = 0; i < cs; i++){
                    arr[i]=ptr[i];
                }
                // clear the old memory
                delete []ptr;
            }
            arr[cs]=data;
            cs++;
        }
        void pop_back(){
            cs--;
        }
        T front(){
            return arr[0];
        }
        T back(){
            return arr[cs-1];
        }
        bool empty(){
            return cs==0;
        }
        int capacity(){
            return ms;
        }
        int size(){
            return cs;
        }
        T at(int i){
            return arr[i];
        }
        // opertator overloading
        T operator[](const int i){
            return arr[i];
        }

};
// if you are not modifying any variable you can declare it as a const
int main(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<"capacity "<<v.capacity()<<endl;
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}