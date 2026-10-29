#include<iostream>
using namespace std;
class stack{
    public:
    string arr[10];
    int top;
    stack(){
      top=-1;
    }
    void push(string url){
        if(top>=10){
            cout<<"hisory full";
        }
        else{
            arr[++top]=url;
            cout<<"Visited";
        }
    }
   void pop(){
    if(top<=-1){
        cout<<"no history";
    }
    else{
        cout<<"going back from"<<arr[top];
        arr[top--];
    }
   }
   void display(){
     if(top<=-1){
        cout<<"no history";
    }
    else{
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
    }
   }
   void peak(){
    if(top<=-1){
        cout<<"Nothing to show";
    }
    else{
        cout<<"You are at:"<<arr[top];
    }
   }
};
int main(){
    stack s;
    int choice;
    string url;
    do{
        cout<<"\n1.push.\n2.pop.\n3.peak.\n4.display.\n5.exit.\nEnter choice:";
        cin>>choice;
        switch(choice){
            case 2:
              s.pop();
              break;
            case 1:
             cout<<"Enter url:";
             cin>>url;
             s.push(url);
             break;
            case 4:
              s.display();
              break;
            case 5:
             cout<<"Exiting";
             break;
             case 3:
                s.peak();
                break;                
            default:
               cout<<"Enter Valid choice";
               break;
        }
    }while(choice!=5);
}
