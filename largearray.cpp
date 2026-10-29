#include<iostream>
using namespace std;
int main(){
    int arr[10]={2,34,1,16,4,55,86,65,3};
    int lar=arr[0];
    for(int i=0;i<10;i++){
        if(lar<arr[i]){
            lar=arr[i];
        }
    }
    cout<<lar;
}