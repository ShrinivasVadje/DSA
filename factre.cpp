#include<iostream>
using namespace std;
int fact(int n){
    if(n<=1)
      return 1;
    int facto;
     return n*fact(n-1);

}
int main(){
    int n;
     cout<<"Enter the number:";
    cin>>n;
    cout<<"Fact:"<<fact(n);

} 