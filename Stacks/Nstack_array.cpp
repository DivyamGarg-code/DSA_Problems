#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/

TIME COMPLEXITY O(1) IN CASE OF PUSH AND POP
SPACE COMPLEXITY O(n+s)
*/
class NStack{
    private:
        int* arr;
        int* top;
        int* next;
        int n,s;
        int freespot;
    public:
        // n->number of stacks s->size of array
        NStack(int N,int S){ // Initialising 
            
            n=N;
            s=S;
            arr=new int[s];
            top=new int[n]{-1};
            next=new int[s];
            for(int i=0;i<s;i++){
                next[i]=i+1;
            }
            // update the last index value to -1
            next[s-1]=-1;
            // Initialising the freespot
            freespot=0;
        }
// pushes the data into Mthh stack and returning true if the data is pushed else return false
        bool push(int data,int m){ // m->stack nuber
            if(freespot==-1){ // check for overflow
                return false;
            }else{
                // find index
                int i=freespot;
                // update freespot
                freespot=next[i];
                //insert element into the array
                arr[i]=data;
                //update next
                next[i]=top[m-1];
                // update top
                top[m-1]=i;
            }
        }
        int pop(int m){
            // just do the reserve steps as of push
            if(top[m-1]==-1){ //check the underflow condition
                return -1;
            }

            int i=top[m-1];
            top[m-1]=next[i];
            next[i]=freespot;
            freespot=i;
            return arr[i];
        }


};
int main(){
    
    return 0;
}