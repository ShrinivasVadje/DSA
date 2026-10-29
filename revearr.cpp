#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(int);
    int rev[n];

        for(int i=0; i<n; i++){
    rev[i] = arr[n-1-i];
}

    
    for(int i=0;i<n;i++){
        cout<<rev[i]<<" ";
    }
}