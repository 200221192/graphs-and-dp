#include<iostream>
#include<stack>
using namespace std ;

// inser element at bottom of the stack done in o(n)

void addElement(stack<int>&s , int size , int element){
    if(s.empty()){
        s.push(element);
        return ;
    }

    int ans = s.top();
    s.pop();

    addElement(s,size,element);

    s.push(ans);
}

int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3) ;
    s.push(4);
    int sz = s.size();
    int ele ;

    cout<<"eneter the element to be add:"<<endl;
    cin>>ele ;

    addElement(s , sz , ele);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

  return 0 ;
}