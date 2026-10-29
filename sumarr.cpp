#include<iostream>
using namespace std;
int main(){
    int i,sum=0;
    int arr[8]={1,2,12,3,44,56,7,87};
    for(i=0;i<8;i++){
        sum+=arr[i];
    }
    cout<<"The sum of the array is="<<sum;
    return 0;
}