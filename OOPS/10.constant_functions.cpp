#include<bits/stdc++.h>
using namespace std;
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

        int getNumerator() const{
            return numerator;
        }
        int getDenominator() const{
            return denominator;
        }
        void setNumerator(int n){
            numerator=n;
        }
        void setDenominator(int d){
            denominator=d;
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
        void add(Fraction f2){ // here in the parameter copy constructor is being called ie copying the values of f2 in this object 
            int lcm=denominator*f2.denominator;
            int x=lcm/denominator;
            int y=lcm/f2.denominator;
            int num=x*numerator+(y*f2.numerator);
            numerator=num;
            denominator=lcm;
            simplify();
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);

    Fraction const f3;
    // compiler will not allow us to call the normal functions through the constant object being made
    // we can only call constant functions through constant objects
    // Constant functions are those which does'nt change any property of current object
    cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;

    return 0;
}