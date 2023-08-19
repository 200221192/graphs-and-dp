#include<iostream>
using namespace std ;
void merge(int *arr , int s , int e){
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid ;

    int *first = new int[len1];
    int *second  = new int[len2];

    int real = s ;

    for(int i = 0 ; i < len1 ; i++){
        first[i] = arr[real++];
    }
    real = mid+1 ;
    for(int i = 0 ; i < len2 ; i++){
        second[i] = arr[real++];
    }

    int index1 = 0 ;
    int index2 = 0 ;
    real = s ;

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[real++] = first[index1++];
        }
        else{
            arr[real++] = second[index2++];
        }
    }

    while(index1 < len1){
         arr[real++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[real++] = second[index2++];
    }
    
}

void mergesort(int *arr , int s , int e){

    //base case
    if(s >= e){
        return ;
    }

    int mid = (s+e)/2;

    mergesort(arr , s , mid);
    mergesort(arr , mid+1 , e);

    merge(arr , s , e);
}
int main(){
    int arr[] = {1 , 10 , 4 , 8 , 3};
    int size = 5 ;
    mergesort(arr ,0 , size-1);
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}