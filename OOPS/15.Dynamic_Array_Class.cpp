#include<bits/stdc++.h>
using namespace std;

/* IMPORTANT Dynamic Array Class
     Copy constructor as well as Copy assignment operator both do shallow copy
*/
class dynamicArray{
        int *data,nextIndex,capacity;
    public:
        dynamicArray(){
            capacity=1;
            nextIndex=0;
            data=new int[capacity];
        }
        dynamicArray(dynamicArray const &d){ // Copy Constructor
            // this->data=d.data; Shallow Copy

            // Deep Copy
            this->data=new int[d.capacity]; // is object ke data main new array bna do
            for(int i=0;i<d.nextIndex;i++){
                data[i]=d.data[i];
            }
            this->nextIndex=d.nextIndex;
            this->capacity=d.capacity;
        }
        void operator=(dynamicArray const &d){ // Copy Assignment Operator
            this->data=new int[d.capacity];
            for(int i=0;i<d.nextIndex;i++){
                data[i]=d.data[i];
            }
            this->nextIndex=d.nextIndex;
            this->capacity=d.capacity;
        }
        void add(int element){
            if(nextIndex==capacity){
                int *newData=new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newData[i]=data[i];
                }
                delete []data;
                data=newData;
                capacity=2*capacity;
            }
            data[nextIndex]=element;
            nextIndex++;
        }
        int get(int i) const{ // making the functions constant as it is not making any changes in the current object
            if(i<capacity){
                return data[i];
            }
            return -1;
        }
        void addAtIndex(int i,int element){ 
            if(i<nextIndex){
                data[i]=element;
            }else if(i==nextIndex){
                add(element);
            }
            return;
        }
        void print() const{
            for(int i=0;i<nextIndex;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();
    dynamicArray d2(d1); // as default copy constructor will be doing shallow copy ie rather than passing the copy it will pass the adress of 1st block of array d1 due to which if in future some changes are made in d1 they will also be reflected in d2. So th avoid that you should create your own copy constructor which is creating a copy of array d1 and copying it in d2 so that in future d1 changes will not be reflected in d2
    d1.addAtIndex(4,100);
    // After deep copy d2 main ab koi changes nhi honge
    d2.print();
    return 0;
}