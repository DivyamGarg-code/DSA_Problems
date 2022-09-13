#include<bits/stdc++.h>
using namespace std;
// Set example unique permutations
// T o get unique permutations and also in lexographical order
void permute(char* a,int i,set<string> &s){
    // Base case
    if(a[i]=='\0'){
        string t(a); // converting the character array into string
        s.insert(t);
        return;
    }
    // recursive case
    for(int j=i;a[j]!='\0';j++){
        swap(a[i],a[j]);
        permute(a,i+1,s);
        swap(a[i],a[j]); // backtracking jab niche se upar jayga, vapis se swap krke original config lekr aayga
    }
}
int main(){
    char a[100];
    cin>>a;
    set<string> s;
    permute(a,0,s);
    for(auto x:s){
        cout<<x<<endl;
    }
    return 0;
}