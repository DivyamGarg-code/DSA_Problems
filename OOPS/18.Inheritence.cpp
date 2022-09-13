#include<bits/stdc++.h>
using namespace std;

// Inheritance Introduction
/*
Inheritance means common properties 
You can make a common class so that common properties can be accessable to other classes that we want ie now we don't need to define the same properties in different classes 

Access Modifier : Protected- It lies in between the public and private modifier ie if we want to give access to only some classes  not all the classes then this modifier is being used

If you declare any property as protected that simply means that this property is only accessible to its child classes 

eg Let suppose you made a class 
Vehicle{
    public-x     Ye property bahar accessable ha
    protected-y  These properties can be accessable outside the class but only through its child classes
    private-z    Ye property bahar accessable hi nhi ha
}

Vehicle : Parent or base class
Car   : child or derived class
*/

class Vehicle{
    private:
        int maxSpeed;
    protected:
        int numTyres;
    public:
        string color;
        Vehicle(){
            numTyres=3;
        }

    
};
// Now how you can inherit this property to the child class
// syntax class child_class_name:access_modifier Parent_Class{}
// private properties are not accessable outside the class but public and protected properties are accessable

// Protected Properties class ke bahar sirf derived classes main use ho sakti ha uske alava use/access nhi kr sakte 

class Car:public Vehicle{ // inheriting the property of vehicle ie protected and public properties are being inherited not the private ones
    public:
        int numGears;
        void print(){
            cout<<numTyres<<endl;
        }
        void get(){
            cout<<numTyres<<endl;
        }
};

/*
2. access modifier : Protected
Now if we want to inherit the properties of vehicle in the car class by the access modifier protected then in that case -
private properties will not be inherited 
protected properties will be inherited as protected
and public properties will now also be inherited as protected
*/

/*
3. access modifier : Private
Now if we want to inherit the properties of vehicle in the car class by the access modifier protected then in that case -
private properties will not be inherited 
public and protected properties will be inherited as private

Now you cant create its child class as it wont be able to access it's private properties
*/
 

int main(){
    Vehicle v;
    v.color="Blue";
    Car c;
    c.color="red";
    c.print();
    return 0;
}