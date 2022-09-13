#include<bits/stdc++.h>
using namespace std;

/* Default Constructor : Just after creating the object this constructor is being called automatically
You can make as many constructors but the constructors must differ based upon the parameterized values that you are passing 
if you create the same constructors then the compiler will throw an error showing constructor overloading

IMPORTANT: FOR EVERY OBJECT OUT OF MANY CONSTRUCTORS ONLY ONE CONSTRUCTOR WILL BE CALLED AT THE TIME OF INITIALIZATION depending on the parmeters passed 

this-> keyword holds the adress of current object

If you are creating a parameterized constructor then you have to pass required parameters while defining the object and if you are not passing the arguments then you must create your own default constructor also to remove compilation error
*/
class Student{
    private:
        int age;
    public:
        int rollno;
        Student(){
            cout<<"Constructor is called!\n";
        }
        Student(int r){
            cout<<"Constructor 2 is called!\n";
            rollno=r;
        }
        Student(int rollno,int a){
            cout<<"Constructor 3 is called!\n";
            // rollno=rollno; the value will not be stored in the class rollno variable because whose scope is nearer that variable is processed
            // but if we write this->rollno as we know this-> keyword holds the adress of current object it means basically we are writing object->rollno ie accessing the rollno at this object's adress
            this->rollno=rollno;
            age=a;
        }
        void display(){
            cout<<age<<" "<<rollno<<endl;
        }
        void setAge(int a,int password){// By giving the password only certain people can have access to modify the age who know the password
            if(password!=123){
                return;
            }      
            if(a<0){
                return;
            }else{
                age=a;
            }
            return;
        }
        int getAge(){
            return age;
        }
};
int main(){
    Student s1;
    Student s2(4);
    Student s3(23,12);
    s3.display();

    // copy constructor : creates the copy at the time of the creation of the object
    Student s4(s3); // same values will be coppied in s4 as that of s3
    // now no default or parameterized constructor is being callled because all the properties of s3 are being copied in s4

    // copy constructor in case of dynamic allocation of object
    Student *s5=new Student(70,21);
    Student s6(*s5);
    Student *s7=new Student(*s5);
    Student *s8=new Student(s3);

    // copy assignment operator (=)
    // copy the values of one object into another after initiallising the object
    Student p1(23,12);
    Student p2(34,65);
    Student *p3=new Student(21,11);
    p1=p2;
    *p3=p2;


    return 0;
}