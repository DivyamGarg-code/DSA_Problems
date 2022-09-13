#include<bits/stdc++.h>
using namespace std;

// By declaring a variable static we can ensure that for each object of same class another copy is not created 
// and also static property is the property of the class not the property of the object
// It is accessed as (name of the class)Student::totalStudents(static property) or with the help of object also like s1.totalStudents
// Static property is initiallised outside the class
// Static functions can only access static data members/ functions : We can't access non statc data members/functions
// Static Functions don't have this keyword
class Student {
    private:
        static int totalStudents; // total number of students present
    public :
    int rollNumber;
    int age;
    Student(){
        totalStudents++;
    }
    int getRollNo(){
        return rollNumber;
    }
    static int getTotalStudents(){ // Static functions
        return totalStudents;
    }

};
int Student::totalStudents=0; // initiallise static data members


int main() {
    // Student s1;
    // cout<<s1.totalStudents<<endl;
    // Student s2;
    // s2.totalStudents=20;
    // cout<<s1.totalStudents;
    Student s1,s2,s3,s4,s5;
    // cout<<Student::totalStudents<<endl;
    cout<<Student::getTotalStudents(); 
}