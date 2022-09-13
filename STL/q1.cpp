// When the data_types vary, we can use templates in which we can have a temporary data type let say T
#include<bits/stdc++.h>
using namespace std;
// template <typename T> // If you want to give the same data type of all the variables created
template <typename T,typename V> // If you want to give different data types to different variables
class Pair{
    private:
        T x;
        V y;
    public:
        void setX(T x){
            this->x=x;
        }
        T getX(){
            return x;
        }
        void setY(V y){
            this->y=y;
        }
        V getY(){
            return y;
        }
};

