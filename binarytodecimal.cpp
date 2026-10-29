#include<iostream>
using namespace std;
void bd(int n){
    int d=0;
    int pow=1;
    int las;
    while(n>0){
        las=n%10;
        d+=pow*las;
        n=n/10;
        pow=pow*2;
    }
    cout<<d;

}
int main(){
    bd(01);
}