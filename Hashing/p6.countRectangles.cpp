#include<bits/stdc++.h>
using namespace std;
// Count Rectangles
// Given n cartisian points, find the number of axis parallel rectangles formed by them
class Point{
    public:
        int x,y;
        Point(){

        }
        Point(int x,int y){
            this->x=x;
            this->y=y;
        }
};

class Compare{
    public:
        bool operator()(Point p1,Point p2){
            if(p1.x==p2.x){ // if x coordinates are same then comparision will be based upon y coordinates
                return p1.y<p2.y;
            }
            return p1.x<p2.x;
        }
};
int count_rectangles(vector<Point> coords){
    int ans=0;
    int n=coords.size();
    // insert all the points in the set
    set<Point,Compare> s; // as point is the custom class therefore you need to create thhe compare function
    for(auto p:coords){
        s.insert(p);
    }
    // run 2 loops
    for(auto it=s.begin();it!=prev(s.end());it++){
        for(auto jt=next(it);jt!=s.end();jt++){
            Point p1=*it;
            Point p2=*jt;
            if(p1.x!=p2.x && p1.y!=p2.y){
                Point p3(p1.x,p2.y);
                Point p4(p2.x,p1.y);
                if(s.find(p3)!=s.end() && s.find(p4)!=s.end()){
                    ans++;
                }
            }
        }
    }
    return ans/2;
     
}
int main(){
    int n;
    cin>>n;
    vector<Point> coordinates;
    while(n--){
        int x,y;
        cin>>x>>y;
        Point p(x,y);
        coordinates.push_back(p);    
    }
    cout<<count_rectangles(coordinates);

    return 0;
}