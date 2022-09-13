#include<bits/stdc++.h>
using namespace std;
/*
Access Modifiers: Public Private and Protected
If the properties are declared/defined in the Private Modifier of a parent class then they are not accessible or changeable outside the class directly but they they are changeable with the help of functions
Functions in the class can access the private properties also

If the properties are declared/defined in the Public Modifier of a parent class then are easily accessible or changeable outside the class 

*/
class Student{
    private:
        int age;
    public:
        int rollno;
        void display(){
            cout<<age<<" "<<rollno<<endl;
        }
        void setAge(int a,int password){// By giving the password only certain people can have access to modify the age who know the password

            if(password!=123){
                cout<<"Sorry incorrect Password So you can't have the access\n";
                return;
            }      
            if(a<0){
                cout<<"Age can't be negative\nSo Please enter correct age\n";

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
    // Creating the objects statically
    Student s1,s2;
    s1.setAge(12,123);
    s1.rollno=101;
    s1.display();
    // Creating the objects dynamically
    Student *s3=new Student;
    (*s3).rollno=24;
    // OR
    // s3->age=12;
    s3->rollno=24;
    s3->setAge(234,12);
    s3->display();
    return 0;
}