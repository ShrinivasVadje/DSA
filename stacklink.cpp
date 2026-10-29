#include<iostream>
using namespace std;
class Node{
    public:
      Node*next;
      string data;
    Node(string url){
        data=url;
        next=NULL;
    }
};
class stack{
         public:
           Node*top;
        stack(){
            top=NULL;
        }
    void push(string val){
         Node*newNode= new Node(val);
        if(top==NULL){
            top=newNode;
        }
        else{
        newNode->next=top;
        top=newNode;
        cout<<"Visited";
        }
    }
    void pop(){
           if(top==NULL){
            cout<<"No history";
           }
           else{
            Node*temp=top;
            top=top->next;
            delete temp;
           }
    }
  void peak(){
    if(top==NULL){
            cout<<"No history";
           }
           else{
            cout<<"You are at:"<<top->data;
           }
  }
  void display(){
     if(top==NULL){
            cout<<"No history";
           }
    else{
        Node*temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next; 
            
        }
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
