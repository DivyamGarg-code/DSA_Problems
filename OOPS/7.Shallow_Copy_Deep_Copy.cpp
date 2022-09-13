#include<bits/stdc++.h>
using namespace std;

class Student{
    int age;
    char *name;
    public:
        Student(int age,char *name){
            this->age=age;
            // shallow copy : Here only the reference/address of 1st block is being passed rather than passing the whole array is passed by reference

            // deep copy
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);

        }
        void display(){
            cout<<name<<" "<<age<<endl;
        }
};
int main(){
    char name[]="abcd";
    Student s1(20,name);
    s1.display();

    name[0]='e';
    Student s2(24,name);
    s2.display();
    // here in the case of character array,the array is being passed by reference,not by value therfore we need to create the copy seperately in every class in order to avoid changes in the objects 
    s1.display();

    return 0;
}  