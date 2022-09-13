#include<bits/stdc++.h>
using namespace std;
// Min and Max stack along with the normal stack
// APPROACH 1
// get Min and Max element in O(1) Time but in O(N) space
class Stack{
    private:
        vector<int> s;
        vector<int> min_s;
        vector<int> max_s;
    public:
        int empty(){
            if(s.size()==0){
                return 1;
            }
            return 0;
        }
        void push(int data){
            s.push_back(data);
            if(min_s.size()==0){
                min_s.push_back(data);
            }else{
                if(data<min_s.back()){
                    min_s.push_back(data);
                }else{
                    min_s.push_back(min_s.back());
                }
            }
            if(max_s.size()==0){
                max_s.push_back(data);
            }else{
                if(data>max_s.back()){
                    max_s.push_back(data);
                }else{
                    max_s.push_back(max_s.back());
                }
            }
        }
        void pop(){
            s.pop_back();
            min_s.pop_back();
            max_s.pop_back();
        }
        int top(){
            return s.back();
        }
        int getMin(){
            return min_s.back();
        }
        int getMax(){
            return max_s.back();
        }
};
int main(){
    Stack s;
    s.push(1);
    cout<<"Min "<<s.getMin()<<endl;
    cout<<"Max "<<s.getMax()<<endl<<endl;
    s.push(5);
    cout<<"Min "<<s.getMin()<<endl;
    cout<<"Max "<<s.getMax()<<endl<<endl;
    s.push(3);
    cout<<"Min "<<s.getMin()<<endl;
    cout<<"Max "<<s.getMax()<<endl<<endl;
    s.push(-1);
    cout<<"Min "<<s.getMin()<<endl;
    cout<<"Max "<<s.getMax()<<endl<<endl;
    return 0;
}