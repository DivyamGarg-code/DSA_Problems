#include<bits/stdc++.h>
using namespace std;
// Creating a fraction class to add 2 fractions and giving the simplified fraction
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
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
        void add(Fraction const &f2){ // here let's pass the object by constant reference ie we can only read the value can't make any change
            int lcm=denominator*f2.denominator;
            int x=lcm/denominator;
            int y=lcm/f2.denominator;
            int num=x*numerator+(y*f2.numerator);
            numerator=num;
            denominator=lcm;
            simplify();
        }
        void multiply(Fraction const &f2){
            numerator=numerator*f2.numerator;
            denominator=denominator*f2.denominator;
            simplify();
        }
};

int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    f1.add(f2);
    f1.print();
    f2.print();
    f1.multiply(f2);
    f1.print();
    f2.print();
    return 0;
}

/*
    int i=5;
    int &k=i; this means k is the reference variable same as i which is also pointing to the same 5 
    but if you write 
    int const &k=i this means k is the constant reference variable same as i which is also pointing to the same 5 but now we cant make any change in the value of i through reference k
*/