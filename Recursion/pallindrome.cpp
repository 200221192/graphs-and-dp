#include<iostream>
using namespace std ;
bool pallindrome(string  name , int i , int j){
    // base case
    if(i > j)
    return true ;

   if(name[i] != name[j])
   return false ;
   else{
    i++;
    j--;
    return pallindrome(name,i,j);
   }

}
int main(){
    string name = "abbccbba";
    bool ans = pallindrome(name , 0 , name.length()-1);
    if(ans){
        cout<<"string is pallindrome:"<<name<<endl;
    }
    else{
        cout<<"not a pallindrome"<<endl;
    }
}