#include<iostream>
using namespace std ;
bool linearSearch(int *arr , int size , int k ){
    if(size == 0){
        return false;
    }
    if(arr[0] == k ){
      return true;  
    }
    else{
        bool rem = linearSearch(arr+1 , size-1 , k);
        return rem;
    }

}
int main(){
    int arr[] = {2 , 6 , 4, 9 , 10};
    int size = 5 ;
    int k ;
    cout<<"enter the key";
    cin>>k;
    cout<<endl;
    bool ans = linearSearch(arr , size , k);
    if(ans){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

}