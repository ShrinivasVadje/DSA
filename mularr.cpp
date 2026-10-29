#include<iostream>
using namespace std;
int main(){
    int i,mul=1;
    int arr[8]={1,2,12,3,44,56,7,87};
    for(i=0;i<8;i++){
        mul*=arr[i];
    }
    cout<<"The mul of the array is="<<mul;
    return 0;
}