#include<bits/stdc++.h>
using namespace std;

/* Operator Overloading 
Post increment operator i++;
int i=5;
int j=++i;  // pre increment means first assign then use
cout<<i<<" "<<j;    o/p i=6 j=6
-------------------
int i=5;
int j=i++; // post increment means first use then assign
cout<<i<<" "<<j;    o/p i=6 j=5

we can't apply nesting in post-increment operator ie (i++)++ is not allowed

Next operator which we want to overload is +=
and in this case nesting is allowed
ie (i+=j)+=j
int i=5,j=3;
(i+=j)+=j;
cout<<i<<" "<<j;
O/P : i=11 j=3
*/

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
        // Post-increment Operator
        Fraction operator++(int){
            Fraction fNew(numerator,denominator);
            numerator=numerator+denominator;
            simplify();
            fNew.simplify();
            return fNew;
        }
        Fraction& operator+=(Fraction const &f2) { // returning the fraction by reference so that if nested function is being called then f1 must undergo appropriate changes 
            numerator=f2.denominator*numerator+(denominator*f2.numerator);
            denominator=denominator*f2.denominator;
            simplify();
            return *this;
        }
};

int main(){
    // Fraction f1(10,2);
    // Fraction f2=f1++;
    // f1.print();
    // f2.print();
    Fraction f1(5,1);
    Fraction f2(3,1);
    (f1+=f2)+=f2;
    f1.print();
    f2.print();
    return 0;
}