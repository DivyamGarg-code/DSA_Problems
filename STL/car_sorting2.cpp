#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
        string name;
        int x,y;
        Car(){}
        Car(string n,int x,int y){
            name=n;
            this->x=x;
            this->y=y;
        }
        int dist(){
            return (x*x+y*y);
        }
};
 bool compare(Car A,Car B){
    int da=A.dist();
    int db=B.dist();
    if(da==db){
        return A.name.length()<B.name.length();
    }
     return da<db;
 }

int main(){
    int n;
    cin>>n;
    vector<Car> v;
    for(int i = 0; i < n; i++){
        string name;
        int x,y;
        cin>>name>>x>>y;
        v.push_back(Car(name,x,y));
    }
    sort(v.begin(),v.end(),compare);
    for(auto i:v){
        cout<<i.name<<" "<<i.x<<" "<<i.y<<endl;
    }
    return 0;
}