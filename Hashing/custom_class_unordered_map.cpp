#include<bits/stdc++.h>
using namespace std;
// const means we cannot modify the value
// Unordered Map Hash Functions of the Custom Class
// If there is a custom class as a key in the unordered map we will have to: 
// step1. define our own hash function 
// step2. in the student class you have to overload the == operator to check if the
// 2 keys(of student class) are equal or not 
// as it could be possible to have the same name but different roll number

class Student{
    public:
        string first_name;
        string last_name;
        string roll_no;
        Student(string fn,string ln,string no){
            first_name=fn;
            last_name=ln;
            roll_no=no;
        }
        // You need to compare the roll number of the current student with the
        // student we are given
        bool operator==(const Student &s)const{
            return roll_no==s.roll_no;
        }
        // if it comes true ie the 2 students we are talking about are same
};

// Hashfunction
class Hashfn{
    public:
    // size_t -> unsigned integer  
        size_t operator()(const Student &s)const{
            return s.first_name.length()+s.last_name.length();
        }
};

int main(){
    unordered_map<Student,int,Hashfn> student_map;

    Student s1("Prateek","Narang","010");
    Student s2("Rahul","Kumar","023");
    Student s3("Prateek","Gupta","030");
    Student s4("Rahul","Kumar","120");

    // Add student marks to hashMap
    student_map[s1]=100;
    student_map[s2]=120;
    student_map[s3]=11;
    student_map[s4]=45;

    for(auto s:student_map){
        cout<<s.first.first_name<<" "<<s.first.roll_no<<" marks:"<<s.second<<endl;
    }

    return 0;
}
