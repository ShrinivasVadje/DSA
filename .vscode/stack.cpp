#include<iostream>
using namespace std;
class stack{
    public:
    int stack[100];
    int top=-1;
    void push(int x){
        if(top>=100){
            cout<<"stack overflow";
        }
        else{
        top++;
        stack[top]=x;
        cout<<"Element added successfully";
        }
    }
    void pop(){
        if(top<0){
            cout<<"Stack underflow";
        }
        cout<<"Element removed successfully";
        top--;
    }
void display(){
    if(top<=-1){
        cout<<"Stack underflow";
    }
    else{
        for(int i=top;i>=0;i--){
            cout<<stack[i];
        }
    }
}

};
int main(){
    stack s;
    int ch,n;
    do{
       cout<<"\n1.push.\n2.pop.\n3.display\n4.exit.\nEnter Choice:";
       cin>>ch;
       switch(ch){
        case 1:
           cout<<"Enter Number:";
           cin>>n;
           s.push(n);
           break;
        case 2:
          s.pop();
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
   

           
         
             
   
