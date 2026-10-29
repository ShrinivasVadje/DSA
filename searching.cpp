#include<iostream>
using namespace std;
     void linear(int n,string arr[],int id[]){
        string name;
        int f=0;
         cout<<"Enter name to search:";
         cin>>name;
            for(int i=0;i<n;i++){
                   if(arr[i]==name){
                      cout<<"Book found";
                      cout<<id[i];
                      f=1;
                      break;
                   }
             }
             if(f==0){
                cout<<"Num not found";
             }
    }
    void binary(int n,string arr[],int id[]){
        int key,s,e,m;
        cout<<"Enter Book id:";
        cin>>key;
        s=0;
        e=n-1;
        while(s<=e){
            m=(s+e)/2;
            if(id[m]==key){
                cout<<"Book found";
                cout<<"Book name:"<<arr[m];
                break;
            }
            else if(key>id[m]){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
    }
    void display(int n,string arr[],int id[]){
        if(n==0){
            cout<<"No books";
        }
        else{
            for(int i=0;i<n;i++){
                cout<<"\nName: "<<arr[i]<<" id: "<<id[i];
            }
        }
    }
int main(){
    int max=100;
    int n,id[max],choice;
    string name[max];
    do{
        cout<<"\n1.Enter Books with id and name.\n2.binary search.\n3.linear search.\n4.display.\n5.exit";
        cin>>choice;
        switch(choice){
            case 1: 
              cout<<"How many";
              cin>>n;
              for(int i=0;i<n;i++){
                cout<<"Book name:";
                cin>>name[i];
                cout<<"ID:";
                cin>>id[i];
              }
              break;
            case 2:
              binary(n,name,id);
              break;
            case 3:
              linear(n,name,id);
              break;
            case 4:
               display(n,name,id);
               break;
            case 5:
               cout<<"Exit";
               break;
            default:
              cout<<"Invalid choice";
              break;
        }
    }while(choice!=5);

}