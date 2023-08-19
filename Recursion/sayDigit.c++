#include<iostream>
using namespace std ;
void sayDigit(int num , string arr[]){
    if(num == 0){
       return;
    }
     int digit = num % 10 ;
     num = num/10 ;
     sayDigit(num , arr);
     cout<<arr[digit]<<" ";
}
int main(){
    string arr[10] = {"zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" ,"nine"};
    cout<<"enter the number:";
    int num ;
    cin>>num ;
    sayDigit(num , arr);

}