#include<iostream>
using namespace std;
void palindrome(int n){
    int re=0,digit;
    int num=n;
    while(n>0){
        digit=n%10;
        re=re*10+digit;
        n=n/10;
    }
    if(num==re){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
}
int main(){
    int n;
    do{
        cout<<"\nEnter number:";
        cin>>n;
        palindrome(n);
    }
    while(n!=-1);
}