#include<iostream>
using namespace std;
int partition(int arr[],int low,int high,int pivot){
    int i,j;
    i=low;
    j=low;  
while(i<=high){
    if(arr[i]>pivot){
        i++;
    }
    else{
        swap(arr[i],arr[j]);
        j++;
        i++;
    }
}
return j-1;
}
int quicks(int arr[],int low,int high){
    if(low<high){
        int pivot=arr[high];
        int pos=partition(arr,low,high,pivot);
       quicks(arr,low,pos-1);
       quicks(arr,pos+1,high);
    }
}

     int main(){
    int i,n;
    cout<<"Enter size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    quicks(arr,0,n-1);
    cout<<"The array after sorting is:";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
