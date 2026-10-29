#include<iostream>
using namespace std;
void selections(int n,int arr[]){
    int i,j,min;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
    cout<<"The array after sorting is:";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
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
    selections(n,arr);

}