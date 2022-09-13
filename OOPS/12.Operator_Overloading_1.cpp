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
        Fraction operator+(Fraction const &f2) const{ // here in the parameter copy constructor is being called ie copying the values of f2 in this object 
            int lcm=denominator*f2.denominator;
            int x=lcm/denominator;
            int y=lcm/f2.denominator;
            int num=x*numerator+(y*f2.numerator);
            Fraction fNew(num,lcm);
            fNew.simplify();
            return fNew;
        }
        Fraction operator*(Fraction const &f2) const{ 
            int num=numerator*f2.numerator;
            int den=denominator*f2.denominator;
            Fraction fNew(num,den);
            fNew.simplify();
            return fNew;
        }
        bool operator==(Fraction f2) const{
            return (numerator==f2.numerator && denominator==f2.denominator);
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.print();
    f2.print();
    Fraction f3=f1+f2;// pehle argument vala this-> main jayga and dusra vala second argument main jayga
    f3.print();
    Fraction f4=f1*f2;
    f4.print();

    if(f1==f2){
        cout<<"is equal\n";
    }else{
        cout<<"Not equal\n";
    }
    Fraction const f5; // it can access only the const functions means jo is object ki properties main koi changes na kare
    return 0;
}