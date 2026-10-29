#include<iostream>
using namespace std;
int main(){
     int k,n,rev=0;
     cout<<"Enter Name:";
     cin>>n;
     while(n>0){
        k=n%10;
        rev=rev*10+n;
        n=n/10;
     }
     cout<<k;
    

}