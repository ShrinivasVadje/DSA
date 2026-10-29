#include<iostream>
using namespace std;
class que{
    public:
    int arr[100];
    int front=-1;
    int rear=-1;
    void enque(int x){
        if(rear>=100){
            cout<<"\nque overflow";
        }
       else if(front==-1){
            front=rear=0;
            arr[front]=x;
            cout<<"\nElement added successfully";
        }
        else{
            rear++;
            arr[rear]=x;
            cout<<"\nElement added successfully";
        }
    }
    void deque(){
        if(front==-1){
            cout<<"Que is empty";
        }
        else{
        front++;
        if(front>rear){
            front=rear=-1;
        }
        cout<<"Removed successfully";
        }
    }
    void display(){
        if(front==-1){
            cout<<"Que is empty";
        }
        else{
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
    }
};
int main(){
    que s;
    int ch,n;
    do{
       cout<<"\n1.push.\n2.pop.\n3.display\n4.exit.\nEnter Choice:";
       cin>>ch;
       switch(ch){
        case 1:
           cout<<"Enter Number:";
           cin>>n;
           s.enque(n);
           break;
        case 2:
          s.deque();
          break;
        case 3:
          s.display();
          break;
        case 4:
          return 0;
           break;
       }
    }
    while(ch!=4);
}
   

           
         
             
   
