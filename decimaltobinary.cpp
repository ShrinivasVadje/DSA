#include<iostream>
using namespace std;
void db(int n){
    int rem;
    int pow=1;
    int b=0;
    while(n>0){
        rem=n%2;    
        b+=rem*pow;
        pow=pow*10;
        n=n/2;
    }
    cout<<b;
}
int main(){
    db(18);
}