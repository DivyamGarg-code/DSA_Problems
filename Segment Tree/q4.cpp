#include<bits/stdc++.h>
using namespace std;

// Bank Transactions
// basically you need to find the maximum number of transactions in which we can skip that transaction in which the net balance can become negative

int countTransactions(int a[],unordered_map<string,int> &m,vector<int> temp,int i,int sum=0){
    if(sum<0){
        return 0;
    }
    string key=to_string(i)+"."+to_string(sum);
    if(m.find(key)!=m.end()){
        cout<<"j\n";
        return m[key];
    }
    if(i<=0){
        if(temp.size()>0){
            for(auto x: temp){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
    int include=INT_MIN;
    if((sum+a[i-1])>=0){
        temp.push_back(a[i-1]);
        include=1+countTransactions(a,m,temp,i-1,sum+a[i-1]);
        temp.pop_back();
    }
    int exclude=countTransactions(a,m,temp,i-1,sum);
    return m[key]=max(include,exclude);
}



int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> temp;
    unordered_map<string,int> m;
    cout<<countTransactions(a,m,temp,n);
    // cout<<countTransactions(a,n);
    return 0;
}