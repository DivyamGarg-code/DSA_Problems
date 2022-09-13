#include<bits/stdc++.h>
using namespace std;
// next permutation of a number
// in worst case max iterations n+ n*(log(n))
// TC O(n*(log(n)))
int main(){
    int n;
    cin>>n;
    int k=INT32_MAX;
    int cnt=log(n)/log(10)+1;
    int a[cnt];
    
    for(int i = 0; i < cnt; i++){
        int b=n%10;
        a[cnt-i-1]=b;
        n=n/10;
    }
    int exist=0;

    for(int i = cnt-2; i>=0; i--){
        if(a[i]<a[i+1]){ // If it is true
            reverse(a+i+1,a+cnt); 
            auto ub=upper_bound(a+(i+1),a+cnt,a[i]);
            int idx=ub-a;
            swap(a[i],a[idx]);
            exist=1;
            break;
        }
    }

    if(exist==1){
        int ans=0;
        int p=1;
        for(int i =cnt-1; i>=0; i--){
            ans+=a[i]*p;
            p=p*10;
        }
        if(ans>k || ans<0){
            cout<<-1;
        }else{
            cout<<ans;
        }

    }else{
        cout<<-1;
    }
    return 0;
}