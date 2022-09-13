#include<bits/stdc++.h>
using namespace std;

void permute(char* a,int i){
    // Base case
    if(a[i]=='\0'){
        cout<<a<<endl;
        return;
    }
    // recursive case
    for(int j=i;a[j]!='\0';j++){
        swap(a[i],a[j]);
        permute(a,i+1);
        swap(a[i],a[j]); // backtracking jab niche se upar jayga, vapis se swap krke original config lekr aayga
    }
}
int main(){
    char a[100];
    cin>>a;
    permute(a,0);
    return 0;
}