#include<bits/stdc++.h>
using namespace std;

// search a string in a grid
// Time Complexity O(m*n*k)
// Space Complexity O(1)
bool solve_row(vector<vector<char>> &v,string p,int i,int j,int n,int m){
    int idx=j;
    int pl=p.size();
    if(m-idx>=pl){
        int cnt=0;
        for(int k=idx;k<m;k++){
            if(v[i][k]==p[cnt]){
                cnt++;
                if(cnt==pl){
                    return true;
                }
            }else{
                break;
            }
        }
    }
    // check for reverse direction
    if(idx+1>=pl){
        int cnt_r=0;
        for(int k=idx;k>=0;k--){
            if(v[i][k]==p[cnt_r]){
                cnt_r++;
                if(cnt_r==pl){
                    return true;
                }
            }else{
                break;
            }
        }
    }
    return false;
}

bool solve_col(vector<vector<char>> &v,string p,int i,int j,int n,int m){
    int idx=i;
    int pl=p.size();
    if(n-idx>=pl){
        int cnt=0;
        for(int k=idx;k<n;k++){
            if(v[k][j]==p[cnt]){
                cnt++;
                if(cnt==pl){
                    return true;
                }
            }else{
                break;
            }
        }
    }
    // check for reverse direction
    if(idx+1>=pl){
        int cnt_r=0;
        for(int k=idx;k>=0;k--){
            if(v[k][j]==p[cnt_r]){
                cnt_r++;
                if(cnt_r==pl){
                    return true;
                }
            }else{
                break;
            }
        }
    }
    return false;
}

bool solve_diagonal(vector<vector<char>> &v,string p,int i,int j,int n,int m){
    int pl=p.size();

    // check for bottom right
    int l_br=1+min(m-j-1,n-i-1); 
    if(l_br>=pl){
        int cnt=0;
        int k=0;
        int i_br=i;
        int j_br=j;
        while(k<pl){
            if(v[i_br][j_br]==p[cnt]){
                cnt++;
                if(cnt==pl){
                    return true;
                }
                k++;
                i_br++;
                j_br++;
            }else{
                break;
            }
        }
    }
    
    // check for top left
    int l_tl=1+min(i,j); 
    if(l_tl>=pl){
        int cnt=0;
        int k=0;
        int i_tl=i;
        int j_tl=j;
        while(k<pl){
            if(v[i_tl][j_tl]==p[cnt]){
                cnt++;
                if(cnt==pl){
                    return true;
                }
                k++;
                i_tl--;
                j_tl--;
            }else{
                break;
            }
        }
    }

    // check for bottom left
    int l_bl=1+min(j,n-i-1); 
    if(l_bl>=pl){
        int cnt=0;
        int k=0;
        int i_bl=i;
        int j_bl=j;
        while(k<pl){
            if(v[i_bl][j_bl]==p[cnt]){
                cnt++;
                if(cnt==pl){
                    return true;
                }
                k++;
                i_bl++;
                j_bl--;
            }else{
                break;
            }
        }
    }

    // check for top right
    int l_tr=1+min(m-j-1,i); 
    if(l_tr>=pl){
        int cnt=0;
        int k=0;
        int i_tr=i;
        int j_tr=j;
        while(k<pl){
            if(v[i_tr][j_tr]==p[cnt]){
                cnt++;
                if(cnt==pl){
                    return true;
                }
                k++;
                i_tr--;
                j_tr++;
            }else{
                break;
            }
        }
    }
    return false;
}
int main(){
   vector<vector<char>> v;
   vector<vector<int>> ans;
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++){
        vector<char> temp;
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            temp.push_back(ch);
        }
        v.push_back(temp);
   }
    string p;
    cin>>p;
    char ch=p[0];
    // For row
    // cout<<solve_diagonal(v,p,0,0,n,m)<<endl;
    // cout<<solve_diagonal(v,p,0,1,n,m)<<endl;
    // cout<<solve_diagonal(v,p,0,2,n,m)<<endl;
    // cout<<solve_diagonal(v,p,0,3,n,m)<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==ch){
                if(solve_row(v,p,i,j,n,m)==true){
                    ans.push_back({i,j});
                    continue;
                }else if(solve_col(v,p,i,j,n,m)==true){
                    ans.push_back({i,j});
                    continue;
                }else if(solve_diagonal(v,p,i,j,n,m)==true){
                    ans.push_back({i,j});
                    continue;
                }
            }

        }
    }
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}