#include<iostream>
#include<stack>
using namespace std ;

// delete middle element from the stack done in O(N)

void Solve(stack<int>&s , int count , int size){
    if(count == size/2){
        s.pop();
        return ;
    }

    int num = s.top() ;
    s.pop();

    Solve(s , count+1 , size);

    s.push(num);
}

void deletemiddle(stack<int>&s , int size)
{
    int count = 0 ;
    Solve(s , count , size);
}

int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int sz = s.size();
    cout<<s.size()<<endl;
    deletemiddle(s , sz);

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
   
    return 0 ;
}