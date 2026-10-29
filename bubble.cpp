#include<iostream>
using namespace std;
int main(){
   int arr[10]={4,2,1,3,5,6,9,8,7,10};
   for(int i=0;i<10;i++){
       for(int j=0;j<10;j++){
        if(arr[j]>arr[i]){
            swap(arr[i],arr[j]);
        }
       }       
   }
   for(int j=0;j<10;j++){
        cout<<arr[j]<<" ";
        }
}