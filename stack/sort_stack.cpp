#include<iostream>
#include<stack>
using namespace std ;


// reverse a stack using recursion O(N)

void insertsort(stack<int>&s , int ele){
   // base case
    if(s.empty()){
        s.push(ele);
        return;

    }
    if(s.top()<ele){
        s.push(ele);
        return ;
    }

    int x = s.top();
    s.pop();

    insertsort(s , ele);

    s.push(x);
}
void sort(stack<int>&s , int size){
    if(s.empty())
    return ;

    int ele = s.top();
    s.pop();

    sort(s , size);

    insertsort(s,ele);

}
int main(){

    stack<int>s;
    s.push(3);
    s.push(-1);
    s.push(31) ;
    s.push(8);
    int sz = s.size();
    sort(s , sz);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

  return 0 ;

}