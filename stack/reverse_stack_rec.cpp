#include<iostream>
#include<stack>
#include<vector>
using namespace std ;

// reverse the stack using recursion

void insertAtBottom(stack<int>&s , int ele){
   if(s.empty()){
        s.push(ele);
        return ;
    }

    int ans = s.top();
    s.pop();

   // recursive call
    insertAtBottom(s,ele);

    s.push(ans);
}

void reverseStack(stack<int>&s){
   /* vector<int>v ;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }

    for(int i = 0 ; i < v.size() ; i++){
        s.push(v[i]);
    }*/

    // base case
    if(s.empty()){
        return ;
    }

    int ele = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s ,ele);

}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    int sz = s.size();

    reverseStack(s);

     while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

   return 0 ;
}