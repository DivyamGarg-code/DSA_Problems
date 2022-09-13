#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50,60,70};
    int n=sizeof(arr)/sizeof(arr[0]);
    // rotate the array 
    rotate(arr,arr+2,arr+n); // rotate(first iterator,jiske about rotate karana ha ,last iterator) 
    for(int i = 0; i <n; i++){ 
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // Apply the same on vector [dynamic array]
    vector<int> v{1,2,3,4,5,6,7};

    //rotate(v.begin(),v.begin()+3,v.end());

    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // next permutation The complexity of the code is O(n*n!) which also includes printing all the permutations.
    next_permutation(v.begin(),v.end());
    // for each loop
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

// C++ program to illustrate
// next_permutation example
int a[] = { 1, 2, 3 };

sort(a, a + 3);

cout << "The 3! possible permutations with 3 elements:\n";
do {
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
} while (next_permutation(a, a + 3));

cout << "After loop: " << a[0] << ' '<< a[1] << ' ' << a[2] << '\n';

// ........................................................................
// C++ program to illustrate
// prev_permutation example

int b[] = { 1, 2, 3 };

sort(b, b + 3);
reverse(b, b + 3);

cout << "The 3! possible permutations with 3 elements:\n";
do {
    cout << b[0] << " " << b[1] << " " << b[2] << "\n";
} while (prev_permutation(b, b + 3));

cout << "After loop: " << b[0] << ' ' << b[1]<< ' ' << b[2] << '\n';

    return 0;
}     