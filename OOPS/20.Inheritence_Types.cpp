#include<bits/stdc++.h>
using namespace std;

/*
Important Watch Video
Types Of Inheritence
1. Single Level Inheritence A->B
2. Multi Level Inheritence  A->B->C
3. Hirarchial Inheritance :  Similar to tree
eg Vehicle: its children Car Bicycle Truck
4. Multiple Inheritence : We have multiple base classes and 1 derived class
means 1 child having multiple(more than 1 parent)
5. Hybrid Inheritence: Combination of hirarchial and muliple  inheritance
*/

class Teacher{
    public:
        string name;
        string age;
        void print(){
            cout<<"Teacher\n";
        }
};

class Student{
    public:
        string name;
        void print(){
            cout<<"Student\n";
        }
};

class TA:public Teacher,public Student{
    public:
        void print(){
            cout<<"TA\n";
        }
};

int main(){
    TA a;
    a.Student::print();
    a.Teacher::name="abcd";
    return 0;
}