#include<iostream>
using namespace std ;

bool isSorted(int *arr , int size){
    if(size == 0 || size == 1)
    return true;

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        return isSorted(arr+1 , size-1);
    }
}
int main(){

    int arr[] = {3,5,6,7,13};
    int size = 5;

    bool ans = isSorted(arr , size);
    if(ans){
        cout<<"array is already sorted"<<endl;
    }
    else{
        cout<<"sorted is not sorted"<<endl;
    }


}