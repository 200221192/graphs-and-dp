#include<iostream>
#include<stack>
using namespace std ;

// identify the redundant brackets using stack  done in O(N)
bool redundant(string str , int size){
  stack<char>s;
  for(int i = 0 ; i <= size ; i++){
    char ch = str[i];
    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        s.push(ch);
    }
    else{
        if(ch == ')'){
            bool isredundant = true ;
            while(s.top() != '('){
                char top = s.top();
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    isredundant = false ;
                }
                 s.pop();
            }
            if(isredundant == true)
            return true ;
            s.pop();
        }
    }
  }
  return false ;
}
int main(){
    string str = "((a+b))";
    int size = str.length();

    cout<<redundant(str , size);
    return 0;

}