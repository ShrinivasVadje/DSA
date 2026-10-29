#include<iostream>
using namespace std;
int fact(int n){
    int fact=1;
    for(int i=n;i>=1;i--){
        fact=fact*i;
    }
    return fact;
}
int bion(int n,int r){
    return (fact(n))/(fact(r)*fact(n-r));
}
int main(){
    cout<<bion(5,2);
}
