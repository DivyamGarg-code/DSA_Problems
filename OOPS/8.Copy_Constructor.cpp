#include<bits/stdc++.h>
using namespace std;

class Student{
    int age;
    public:
        char *name;
        Student(int age,char *name){
            this->age=age;
            // shallow copy : Here only the reference/address of 1st block is being passed rather than passing the whole array is passed by reference

            // deep copy
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);

        }
        //Copy Constructor 
        // Now we should pass by reference otherwise it will create infinite loop of copy the values
        Student(Student const &s){ // constant reference variable
            this->age=s.age;

            // this->name=name // shallow copy

            // Deep Copy
            this->name=new char[strlen(s.name)+1];
            strcpy(this->name,s.name);
        }
        void display(){
            cout<<name<<" "<<age<<endl;
        }

};
int main(){
    char name[]="abcd";
    Student s1(20,name);
    s1.display();

    Student s2(s1); // whenever we use inbuilt copy constructor it will always do the shallow copy
    // ie agar s2 main changes karenge to s1 main bhi reflect honge so we should try to make our own copy constructor
    s2.name[0]='x';
    s2.display();
  
    s1.display();

    return 0;
}  