#include<iostream>
using namespace std ;
void bubblesort(int *arr , int size){
    if(size == 0 || size == 1){
        return ;
    }

    for(int i = 1 ; i < size ; i++){
    if(arr[i] > arr[i+1]){
        swap(arr[i] , arr[i+1]);
    }
    }
    bubblesort(arr , size-1);
}
int main(){
    int arr[] = {1 , 10 , 4 , 8 , 3};
    int size = 5 ;
    bubblesort(arr , size);
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}