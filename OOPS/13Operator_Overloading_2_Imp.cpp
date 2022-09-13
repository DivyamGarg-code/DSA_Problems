#include<bits/stdc++.h>
using namespace std;

// Operator Overloading
// Creating a fraction class to add 2 fractions and giving the simplified fraction
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(){

        }
        Fraction(int numerator,int denominator){
            this->numerator=numerator;
            this->denominator=denominator;
        }
        void print(){
            cout<<numerator<<" / "<<denominator<<endl;
        }
        void simplify(){
            int gcd=1;
            int j=min(this->numerator,this->denominator);
            for(int i=j;i>=0;i--){
                if(this->numerator%i==0 && this->denominator%i==0){
                    gcd=i;
                    break; 
                }
            }
            this->numerator=this->numerator/gcd;
            this->denominator=this->denominator/gcd;
            return;
        }
        // Pre-increment Operator
        Fraction& operator++(){
            numerator=numerator+denominator;
            simplify();
            return *this;
        }
};

int main(){
    Fraction f1(10,2);
    f1.print();
    Fraction f2=++(++f1);
    // Here we will see f1 value which should ideally come same as that of f2 is not being incremented. Why?
    // because when we are calling ++f1 it is directly returning the content of f1 and this content is stored in temporary buffer memory which is not the f1 and when again ++ operation is performed it is not making any changes in f1 as the content/object present in buffer's memory is updated not the actual f1 so you should return the fraction by reference so that temporary memory na create create ho jo bhi changes han us object main hi reflect ho jay
    f2.print(); 
    f1.print();
    return 0;
}