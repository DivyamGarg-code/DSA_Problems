#include<bits/stdc++.h>
using namespace std;

/*
Important You Should watch the video
Whenever you are creating an object of child class you first need to initiallise values of its parent class 
and when you create the object of child class, the default constructor of parent class is being called first

Order of constructor call in case of inheritence
A->B->C : B class inherit properties of A then C class inherit properties of C
A a; A() A class ka constructor call hoga
B b; A() then B() Pehle A class ka constructor call hoga then B class ka
C c; A() then B() then C() class ka constructor call hoga

And destructor ka order bilkul reverse hota ha

Any child class can implicitly call only its nearest parent class 
*/

class Vehicle{
    private:
        int maxSpeed;
    protected:
        int numTyres;
    public:
        string color;
        Vehicle(){
            cout<<"Vehicle Default Constructor is called\n";
        }
        Vehicle(int z){
            cout<<"Vehicle Parameterized Constructor is called\n";
            maxSpeed=z;
        }
        ~Vehicle(){
            cout<<"Vehicle destructor is called\n";
        }    
};
class Car:public Vehicle{ 
    public:
        int numGears;
        Car(){
            cout<<"Car's Default Constructor is called\n";
        }
        Car(int x,int y):Vehicle(5){ // This is the constructor of the class in which its parent class contains a parameter
            cout<<"Car's Default Constructor is called\n";
            numGears=y;
        }
        void print(){
            cout<<"Num Tyres : "<<numTyres<<endl;
            cout<<"color : "<<color<<endl;
            cout<<"Num gears : "<<numGears<<endl;
        }
        ~Car(){
            cout<<"Car's Destructor\n";
        }
};

class HondaCity:public Car{
    public:

        HondaCity(int x,int y):Car(x,y){
            cout<<"Honda City Constructor\n";
        }
        ~HondaCity(){
            cout<<"Honda City Destructor\n";
        }

};
int main(){
    Vehicle v;
    v.color="Blue";
    Car c; // By default pehle vehicle ka default constructor call hoga 
    // But if you want to call the parameterized constructor of parent class then see line 41
    c.numGears=3;
    HondaCity hc(3,5);
    return 0;
}