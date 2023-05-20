#include<iostream>
#include<stack>
using namespace std ;

//reverse a string using stack Tc-0(1) sc-0(n)
int main(){
    string str = "neha" ;
    stack<int>s ;

    for(int i = 0 ; i < str.length() ; i++){
        char ch = str[i];
        s.push(ch);

    }
    string ans = "";

    while(!s.empty()){
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout<<ans<<endl;


}