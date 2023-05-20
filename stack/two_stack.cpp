#include <iostream>
using namespace std;
class twostack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    twostack(int s){
        this->size = s;
        top1 = -1 ;
        top2 = s ;
        arr = new int[s];
    }

    void push1(int element){
        if(top2-top1 > 1){
            top1++ ;
            arr[top1] = element;
        }
        else{
            cout<<"stack overflow";
        }
    }

    void push2(int element){
         if(top2-top1 > 1){
            top2-- ;
            arr[top2] = element;
        }
        else{
            cout<<"stack overflow";
        }

    }

    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans ;
        }
        else{
            cout<<"stack underflow";
            return -1 ;
        }

    }

    int pop2(){
        if(top1 < size){
            int ans = arr[top2];
            top2++;
            return ans ;
        }
        else{
            cout<<"stack underflow";
            return -1 ;
        }

    }
};
int main()
{
    twostack st(5);

    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(5);
    st.push2(4);

    cout<<st.pop1()<<endl;
    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
    cout<<st.pop2()<<endl;

}