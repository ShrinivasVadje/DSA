#include<iostream>
using namespace std;
void display(int n,int id[],string name[]){
         for(int i=0;i<n;i++){
            cout<<"Book Id:"<<id;
            cout<<"Name:"<<name;
         }
        }
void linearsearch(int n,int id[],string name[],string key){
    int f=0;
    for(int i=0;i<n;i++){
        if(name[i]==key){
              cout<<"Book found"<<"\nid:"<<id[i];
              f=1;
              break;
        }
    }
    if(f==0){
        cout<<"Book not found";
    }
}
void binarysearch(int n,int id[],string name[],string key ){
    int s=0,f=0;
    int e=n-1;
    while(s>e){
        int m=(s+e)/2;
        if(name[m]==key){
            cout<<"Book found"<<"\nid:"<<id[i];
              f=1;
              break;
        }
        else if(name[m]>key){
            s=m+1;
        }
        else if(name[m]<key){
            e=m-1;
        }

    }
}