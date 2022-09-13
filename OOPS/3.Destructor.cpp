#include<bits/stdc++.h>
using namespace std;

/* Destructor : Used to deallocate the memory of the object
It has same name as that of our class
It has no return type
It has no input arguments
~class_name(){

}
It is created automatically
*/
class Student{
    private:
        int age;
    public:
        int rollno;
        Student(){
        }
        void display(){
            cout<<age<<" "<<rollno<<endl;
        }
        Student(int rollno,int a){
            this->rollno=rollno;
            age=a;
            display();
        }
        ~Student(){
            cout<<"Destructor is called!\n";
        }
};

int main(){
    Student p1(23,12); // destructor is being called
    Student p2(34,65); // destructor is being called
    Student *p3=new Student(21,11); // Here the destructor will not be called as p3 is a pointer pointing to the object whose memory is in the heap so we have to delete the p3 pointer in order to call the destructor for the object to whom p3 is pointing 
    p1=p2;
    *p3=p2;
    // delete p3;
    return 0;
}