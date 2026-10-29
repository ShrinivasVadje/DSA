#include<iostream>
using namespace std;
int linears(int s,int arr[],int t){
    int f=0;
    cout<<"The array is: ";
    for(int i=0;i<s;i++){
        cout<<arr[i];
        cout<<" ";
    }
    cout<<endl;
    for(int i=0;i<s;i++){
        if(t==arr[i]){
            cout<<"\nTarget found at index="<<i;
            f=1;
            break;
        }
    }
    if(f==0){
        cout<<"Target not found";
    }
}
int main(){
    int t;
    int arr[10]={23,2,1,3,34,66,7,87,9,33};
    cout<<"Enter the Target:";
    cin>>t;
    linears(10,arr,t);



}