#include<iostream>
using namespace std;
int main(){
    int i,j,t;
    bool flag=true;
    int arr[10]={1,2,12,2,34,5,6,7,8,-2};
    cout<<"Enter target=";
    cin>>t;
    for (i=0;i<10;i++){
        for (j=i+1;j<10;j++){
            if(arr[i]+arr[j]==t){
                   cout<<"The sum is found at index "<<i<<" and index "<<j;
                   cout<<"\nThe Numbers are "<<arr[i]<<" and "<<arr[j];
                   flag=false;
            }
        }
        if (flag==false) break;
    }
}