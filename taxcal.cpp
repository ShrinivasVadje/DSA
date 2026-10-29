#include<iostream>
using namespace std;
int main(){
    float income;
    float tax;
    cout<<"Emter your income:";
    cin>>income;
    if(income<=20000){
        tax=0;
    }
    else if(income<=40000){
        tax=(income-20000)*0.10;
    }
    else if(income<=60000){
        tax=((20000)*0.10)+((income-40000)*0.20);
    }
    else{
        tax=((20000)*0.10)+((20000)*0.20)+((income-60000)*0.30);
    }
    cout<<"Tax for Your income:"<<tax;
}