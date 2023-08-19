#include<iostream>
using namespace std ;
int sumarr(int *arr , int size){
    //base case
    if(size == 0){
        return 0 ;
    }
    if(size == 1){
        return arr[0];
    }

    int rem = sumarr( arr+1 , size-1);
    int sum = arr[0] + rem ;
    return sum ;
}
int main(){
    int arr[] = { 2 , 9 , 5 , 78};
    int size = 4 ;
    int sum = sumarr(arr , size);
    cout<<"sum is"<<" "<<sum;

}