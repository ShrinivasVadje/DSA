#include<iostream>
using namespace std;
int main(){
    int arr[100],m,e,s,n,num;
    cout<<"\nEnter the size of the array";
    cin>>n;
    cout<<"\nEnter the elements of the array (in sorted)";
    for(int i=0;i<n;i++){
         cin>>arr[i];
}
cout<<"\nThe elements of the array";
    for(int i=0;i<n;i++){
         cout<<" "<<arr[i];
}
s=0;
e=n-1;
cout<<"Enter the number to find:";
cin>>num;
int flag=0;
while(s<=e){
    m=(s+e)/2;
    if(num==arr[m]){
       cout<<"Number found at index:"<<m;
       flag=1;
       break;
}
    else if(num>arr[m]){
          s=m+1;
}
   else if(num<arr[m]){
         e=m-1;
}
}
if(flag==0){
    cout<<"Number not found";
}
}
