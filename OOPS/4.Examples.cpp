#include<bits/stdc++.h>
using namespace std;

// Examples

class Student{
    private:
        int age;
    public:
        int rollno;
        Student(){
            cout<<"Constructor 1 is called\n";
        }
        Student(int r){
            cout<<"Constructor 2 is called\n";
            rollno=r;
        }
        Student(int rollno,int a){
            cout<<"Constructor 3 is called\n";
            this->rollno=rollno;
            age=a;
        }
        
};

int main(){
    Student s1; // Constructor 1 is called
    Student s2(101); // Constructor 2 is called
    Student s3(20,102); // Constructor 3 is called
    Student s4(s3); //Copy constructor
    s1=s2; // Copy assignment operator
    Student s5=s4; // Now compiler will treat it like a copy constructor ie s5(s4)
    return 0;
}