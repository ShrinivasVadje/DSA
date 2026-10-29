#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i;
    vector<int>v(5,5);
    for(i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
    v.resize(10);//size increased
    cout<<"enter num=";
    for(i=0;i<10;i++)
    {
        cin>>v[i];

    }
    for(i=0;i<10;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}