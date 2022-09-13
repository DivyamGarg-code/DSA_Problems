#include<bits/stdc++.h>
using namespace std;
/*
Default Constructor
Copy Constructor
Copy Assignment Operator
Addition Subtraction and Multiplication
*/
class Polynomial{
    int *degCoeff;
    int degree;
    int capacity;
    public:
        Polynomial(){
            degree=0;
            capacity=1;
            degCoeff=new int[1]{0};
        }
        void setCoefficient(int i,int data){
            if(i>capacity){
                return;
            }
            if(i==capacity){
                int *newdegCoeff=new int[2*capacity]{0};
                capacity=2*capacity;
                for(int j=0;j<degree;j++){
                    newdegCoeff[j]=degCoeff[j];
                }
                delete []degCoeff;
                degCoeff=newdegCoeff;
            }
            degCoeff[i]=data;
        }
        void print(){
            for(int i=0;i<degree;i++){
                if(degCoeff[i]!=0){
                    cout<<degCoeff[i]<<"x"<<i<<" ";
                }
            }
            cout<<endl;
        }

};
int main(){
    int count1,count2,choice;
    cin >> count1;
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    // cin >> count2;
    // int *degree2 = new int[count2];
    // int *coeff2 = new int[count2];
    // for(int i=0;i < count2; i++) {
    //     cin >> degree2[i];
    // }
    // for(int i=0;i < count2; i++) {
    //     cin >> coeff2[i];
    // }
    // Polynomial second;
    // for(int i = 0; i < count2; i++){
    //     second.setCoefficient(degree2[i],coeff2[i]);
    // }

    return 0;
}