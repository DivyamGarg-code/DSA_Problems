#include<bits/stdc++.h>
using namespace std;

// insertion and deletion in priority queue takes O(logn) time;

int main(){
    cout<<"Using Priority Queue\n";
    // max heap;
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top();

    // Min Heap
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    return 0;
}      