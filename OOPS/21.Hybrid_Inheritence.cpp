#include<bits/stdc++.h>
using namespace std;

/*
Hybrid Inheritence: Combination of hirerchial and multilevel inheritence

In case of hirerchial inheritence By adding virtual keyword while inheriting parent classes the common class construtor will not be called by it's child classes again and again it will called one's
We use virtual classes to avoid creation of copies
// internal working is like ke car and truck ke pass ek pointer pda ha jo vehicle ko point kr rha ha uski copy create nhi hua in child classes main in actual
Aur bus directly vehicle class ka constructor call karega
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
        void print(){
            cout<<"Vehicle\n";
        }
        ~Vehicle(){
            cout<<"Vehicle destructor is called\n";
        }    
};
class Car:virtual public Vehicle{ 
    public:
        int numGears;
        Car(){
            cout<<"Car's Default Constructor is called\n";
        }
        void print(){
            cout<<"Car\n";
        }
        ~Car(){
            cout<<"Car's Destructor\n";
        }
};

class Truck:virtual public Vehicle{
    public:
        Truck(){
            cout<<"Truck's Default Constructor is called\n";
        }
        void print(){
            cout<<"Truck\n";
        }
};

class Bus:public Car,public Truck{
    public:
        Bus(){
            cout<<"Bus's Default Constructor is called\n";
        }
        void print(){
            cout<<"Bus\n";
        }
        ~Bus(){
            cout<<"Bus's Destructor\n";
        }
};
int main(){
    Bus b;
    b.print();
    b.Car::print(); // You need to specifically mention kis class ke function ko call karna ha if multiple inhereted classes have same name 
    return 0;
}