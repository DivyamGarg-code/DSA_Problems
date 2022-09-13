#include<bits/stdc++.h>
using namespace std;

// TC of insertion and Deletion is O(log(n))
class heap{
    public:
        int a[100];
        int size;
        heap(){
            a[0]=-1;
            size=0;
        }
        void insert(int val){
            size=size+1;
            int idx=size;
            a[idx]=val;// insert the element to the last position 
            while(idx>1){ // then bring the element to it's correct position
                int parent=idx/2;
                if(a[parent]<a[idx]){
                    swap(a[parent],a[idx]);
                    idx=parent;
                }else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        void deleteinHeap(){
            if(size==0){
                cout<<"nothing to delete\n";
                return;
            }
            // step 1 Repalce it with the last element
            a[1]=a[size];
            // step 2 delete the last element
            size=size-1;
            //step 3 take the root node to its correct position
            int i=1;
            while(i<size){
                int largest=i;
                int left=2*i;
                int right=2*i+1;
                if(left<size && a[largest]<a[left]){
                    largest=left;
                }
                if(right<size && a[largest]<a[right]){
                    largest=right;
                }
                if(largest!=i){
                    swap(a[largest],a[i]);
                    continue;
                }else{
                    return;
                }
        }
    }
};

// This algorithm takes log(n) time to place the element to its correct position
void heapify(int a[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && a[largest]<a[left]){
        largest=left;
    }
    if(right<n && a[largest]<a[right]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
        
    }
}
int main(){
    heap h;
    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(50);
    h.insert(52);
    h.print();
    h.deleteinHeap();
    h.print();
    int a[5]={-1,52,54,53,50};
    int n=4;
    for (int i=n/2;i>0;i--){
        heapify(a,n,i);
    }
    cout<<"Printing the array now\n";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}