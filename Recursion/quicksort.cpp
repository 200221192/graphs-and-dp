#include<iostream>
using namespace std;
int partition(int *arr , int s , int e){

    // select the pivot element
    int pivot = arr[s] ;
    int count = 0 ;

   // count all the element smaller than pivot
    for(int i = s+1 ; i <= e ; i++){
        if(arr[i] <= pivot ){
           count++ ;
        }
    }

    // place pivot at its correct position
    int pivotindex = s + count ;
    swap(arr[s] , arr[pivotindex]);

    // order the left and right part
    int i = s , j = e;

    while(i < pivotindex && j > pivotindex){
        if(arr[i] <= pivot){
            i++ ;
        }
        if(arr[j] > pivot){
            j-- ;
        }
        if(i < pivotindex && j > pivotindex){
            swap(arr[i] , arr[j]);
        }
    }
   return pivotindex ;

}

void quicksort(int *arr , int s , int e){
    // base case
    if(s >= e)
    return ;

    // find pivot element right place
    int p = partition(arr , s , e);

    // sort the left part
    quicksort(arr , s , p);

    // sort the right part
    quicksort(arr , p+1 , e);

}
int main(){
    int arr[] = {2 , 9 , 6 , 4 ,34};
    int size = 5 ;
    quicksort(arr,0,size-1);

    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}