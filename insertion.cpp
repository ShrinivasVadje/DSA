#include<iostream>
using namespace std;
int main(){
       int arr[10]={4,2,1,3,5,6,9,8,7,10};
       for(int i=1;i<10;i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<curr){
            swap(arr[j],arr[j+1]);
         j--;
        }
        arr[j+1]=curr;
       }
       for(int j=0;j<10;j++){
        cout<<arr[j]<<" ";
        }

}
