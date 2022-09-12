#include<bits/stdc++.h>
using namespace std;
/* 2D CHARACTER ARRAY
    cin>>a[i][j] Take input as a single character
    cin>>a[i]  Means pointing to the i_th row  
*/
int main(){
    // Initiallizing a character array
    //char b[][10]={{'a','b','\0'},{'d','e','f','\0'}}; // have 2 rows and 10 no. of columns
    char b[][10]={"hello","what's up"};
    cout<<b[0]<<endl;
    cout<<b[1]<<endl;



    char a[100][100];
    // read a list of strings and we will store them in the 2D character array
    int n;
    cin>>n;
    cin.get();
    for(int i = 0; i < n; i++){
        cin.getline(a[i],100);
    }
    // Print out all the strings
    for(int i = 0; i < n; i++){
        cout<<a[i]<<endl; 
    }
    return 0;
}
