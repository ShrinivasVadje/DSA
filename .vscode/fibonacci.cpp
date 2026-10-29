#include<iostream>
using namespace std;
int main(){
    int n,first=0,sec=1,next;
    cout<<"Enter num:";
    cin>>n; 
    for(int i=0;i<=n;i++){
        cout<<" "<<first;
        next=first+sec;
        first=sec;
        sec=next;
    }
}