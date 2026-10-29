#include<iostream>
using namespace std;
void fact(int x){
    int  f=1;
    for(int i=x;i>=1;i--){
            f=f*(i);
    }
    cout<<f;

}
int main(){
    fact(3);
}