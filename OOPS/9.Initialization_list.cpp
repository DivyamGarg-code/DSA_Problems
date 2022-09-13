#include<bits/stdc++.h>
using namespace std;
/*
int a=5;
int const b=a;   correct
int const b;
b=a;             incorrect

int i=5;
//  in case of reference variable
int &j=i;       correct
int &j;
j=i;            incorrect

This problem can be solved with the help of initialization list in classes
*/
class Student{
    public:
        int age;
        const int rollNumber; // ie ek baar assign karne ke baad change nhi kar sakte

        int &x; // Let suppose it to be the reference variable of age so it must have the value at the time of initialization otherwise it will give error
        // But with the help of the initialization list we can solve this problem also

        // Jab ek baar variable constant initiallise kar diya then we have to call the initialization list in order to assign the value to const variable
        Student(int r):rollNumber(r),x(this->age){ // Using Initialization List
        }
        // You can initialise multiple values also ie non static values with the help of initialization list
        Student(int r,int age):rollNumber(r),age(age),x(this->age){ 

        }
};
int main(){
    Student s1(101);
    s1.age=101;
    return 0;
}