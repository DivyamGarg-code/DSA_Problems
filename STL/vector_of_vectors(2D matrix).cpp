#include<bits/stdc++.h>
using namespace std;
// vector of vectors
int main(){
    // define the vector of vectors
    vector<vector<int>> stuff; // simlar to 2d matrix
    // fill the inner vector,then insert it into outer vector
    // creating 3x3 matrix
    for(int i = 0; i < 3; i++){ // outer loop
        vector<int> temp;
        for(int j = 0; j < 3; j++){
            temp.push_back(i);
        }
        stuff.push_back(temp);
    }
    // display all the elements to the user
    for(int i = 0; i < stuff.size(); i++){
        for(int j = 0; j < stuff[i].size(); j++){
            cout<<stuff[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}