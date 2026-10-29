#include<iostream>
using namespace std;
int main(){
     int arr[100],n,num;
     cout<<"Enter the Size of the array";
     cin>>n;
     cout<<"Enter the elements of the array";
     for(int i=0;i<=n;i++){
             cin>>arr[i];
     }
   cout<<"The elements of the array:";
  for(int i=0;i<=n;i++){
     cout<<" "<<arr[i];
}
   cout<<"Enter the number you want to find out";
   cin>>num;
   for(int i=0;i<=n;i++){
      if(arr[i]==num){
           cout<<"Number found at Position:"<<i;
          break;
}
else{
    cout<<"Number not found";
}
}
    

}