#include<bits/stdc++.h>
using namespace std;

/*
Polymorphism means many forms
polymorphism occurs when there is a hierarchy of classes and they are related by inheritance. C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

Types:-

1. Compile Time Polymorphism-
i)Function Overloading 
egs of + operator 2+3=5, 1.5+3.5=5.0 'a'+'b'=some int value here + function is behaving differently for addition of different data types
int test(int a,int b){}
int test(int a){}
int test(){}
Compiler can differentiate these 3 functions based upon the arguments passed but let suppose we also have 
void test(){}
now the compiler will not be able to differentiate the 2 functions having same name but different return types

ii) Function Overridding/Method Overridding
Let suppose the child class have the same function name as that of it's parent class in that case the parent's class fuction is being overriden by it's child class

2. Run Time Polymorphism
*/

class Vehicle{
    public:
     void print(){
        cout<<"Vehicle\n";
     }
};

class Car:public Vehicle{
    public:
     void print(){
        cout<<"Car\n";
     }
};
int main(){
    Vehicle v;
    Car c;
    v.print(); // Vehicle ka print function call hoga
    c.print(); // Car ka print function call hoga but let suppose if it dont have print function to vehicle class ka function call hoga and agar vehicle ke pass bhi print function nhi ha then error aayga
    Vehicle *v1=new Vehicle;
    Vehicle *v2;
    v2=&c; // Remember 1 thing ke parent class ka pointer can point to it's same class as well as it's child class but child class ka pointer apni parent class ko point nhi kar sakta

// NOTE: Jab bhi base class ka pointer apni child class ko point kar rha hoga in that case we can access only those properties which are in the base class,we cant access any property of child class 
// Internal working when you are declaring the pointer v2 , vo sirf apni class type check karega it will not see ke vo kisko point kar rha ha and this decision is taken at the COMPILE TIME only that's why it is printing base class print function and not the child's class print function
    v1->print();
    v2->print(); // The decision is taken at the compile time only that whose print function will be called that's why it is not checking to whom v2 is pointing 
    return 0;
}