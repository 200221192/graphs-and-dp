#include<iostream>
using namespace std ;
void bubblesort(int *arr , int size){
   for(int i = 1 ; i < size ; i++){
    for(int j = 0 ; j < size-i ; j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j] , arr[j+1]);
        }
    }
   }
}
int main(){
    int arr[] = {1 , 10 , 4 , 8 , 3};
    int size = 5 ;
    bubblesort(arr , size);
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}