#include<iostream>
using namespace std ;
bool binarySearch(int *arr , int left ,int right , int k ){
    if(left > right)
    return false;

    int mid = left + (right-left)/2;
    if(arr[mid] == k)
    return true;

    if(arr[mid]< k){
        return binarySearch(arr , mid+1 , right , k);
    }
    else{
       return binarySearch(arr , left , mid-1 , k);
    }

}
int main(){
    int arr[] = {2 , 6 , 4, 9 , 10};
    int size = 5 ;
    int k ;
    cout<<"enter the key";
    cin>>k;
    cout<<endl;
    bool ans = binarySearch(arr , 0 , size , k);
    if(ans){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

}