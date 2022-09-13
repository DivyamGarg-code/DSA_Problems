#include<bits/stdc++.h>
using namespace std;

// 4 sum
int main(){
    vector<int> v;
    vector<vector<int>> result;
    int n;
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int l,m;
    sort(v.begin(),v.end());
    int i=0;
    int j;
    while(i<n-1){
        j=i+1;
        while(j<n){
            if((n-j-1)>=2){ // possibly there could be a solution
                int sum=k-(v[i]+v[j]);
                if((sum>=0)){
                    l=j+1;
                    m=n-1;
                    while(l<m){
                        if((v[l]+v[m])==sum){
                            result.push_back({v[i],v[j],v[l],v[m]});
                            int prev_left=v[l]; // skip duplicates 
                            l++;
                            while(l<=m){
                                if(prev_left==v[l]){
                                    l++;
                                }else{
                                    break;
                                }
                            }

                            int prev_right=v[m]; // skip duplicates 
                            m--;
                            while(m>=l){
                                if(prev_right==v[m]){
                                    m--;
                                }else{
                                    break;
                                }
                            }

                        }else if((v[l]+v[m])<sum){
                            int prev=v[l];
                            l++;
                            while(l<=m){
                                if(prev==v[l]){
                                    l++;
                                }else{
                                    break;
                                }
                            }

                        }else{
                            int prev=v[m];
                            m--;
                            while(m>=l){
                                if(prev==v[m]){
                                    m--;
                                }else{
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        
            int prev_j=v[j]; // skip duplicates 
            j++;
            while(j<n){
                if(prev_j==v[j]){
                    j++;
                }else{
                    break;
                }
            }
        }

        int prev_i=v[i]; // skip duplicates 
        i++;
        while(i<n-1){
            if(prev_i==v[i]){
                i++;
            }else{
                break;
            }
        }
    }
    for(auto x:result){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}