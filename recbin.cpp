#include<iostream>
using namespace std;
int binary(int arr[],int s,int e,int num){
    int m=(s+e)/2;
    int f=0;
    if(num==arr[m]){
       cout<<"Num found at index:"<<m;
       f=1;
}
else if(num>arr[m]){
    binary(arr,m+1,e,num);
}
else if(num<arr[m]){
    binary(arr,s,m-1,num);
}
if(f==0){
   cout<<"Number not found";
}
}
int main(){
   int n,s,e,num,arr[100];
   cout<<"Enter the size of the array";
   cin>>n;
   cout<<"Enter the numbers:";
   for(int i=0;i<n;i++){
     cin>>arr[i];
}
   cout<<"Enter the number";
   cin>>num;
    binary(arr,0,n,num);
}   