#include<bits/stdc++.h>
using namespace std;
// cin : to read a word
// cin.get() : can also store special characters
// cin.getline() : to read a paragraph or line

void readline(char a[],int n,char delimeter='\n'){
    int i=0;
    char ch=cin.get();
    while(ch!=delimeter){
        a[i]=ch;
        i++;
        if(i==n-1){
            break;
        }
        ch=cin.get();
    }
    a[i]='\0'; // store null character at the end of the data written
}

int main(){
    // char a[]={'1','2','3','\0'};
    // char b[]="hello"; // automatically have '\0' at the end
    // cout<<sizeof(a)<<"\n";
    // char b[100];
    
    //If you want to get input seperated by space use cin.getline()
    // cin.getline(b,100,'.'); // cin.getline(array,max size,delimeter(optional)) Here the delimeter is by default the new line character \n
    //                     //  It indicate when to stop
    // cout<<b;
    char a[1000];
    readline(a,1000,'$'); // user defined getline function
    cout<<a;// continuosly print until the null character
 

}

