#include<bits/stdc++.h>
using namespace std;

// ComplexNo const &c2 by making the parameter const you can only read the values can't make the changes
class ComplexNo{
    private:
        int real,img;
    public:
    ComplexNo(int r,int i){
        real=r;
        img=i;
    }
    void display(){
        cout<<"Complex No. is "<<real<<" +i"<<img<<endl;
        return;
    }
    void plus(ComplexNo const &c2){
        real=real+c2.real;
        img=img+c2.img;
        display();
    }
    void multiply(ComplexNo const &c2){
        int r=(real*c2.real)-(img*c2.img);
        int i=(img*c2.real)+(real*c2.img);
        real=r;
        img=i;
        display();
    }
};
int main(){
    int real1,img1,real2,img2;
    cin>>real1>>img1>>real2>>img2;
    ComplexNo c1(real1,img1);
    ComplexNo c2(real2,img2);
    int choice;
    cin>>choice;
    if(choice==1){
        c1.plus(c2);
    }else if(choice==2){
        c1.multiply(c2);
    }
    return 0;
}