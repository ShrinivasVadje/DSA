#include<iostream>
using namespace std;
class Node{
    public:
      string name;
      Node*next;
    Node(string n){
        name=n;
        next=NULL;
    }
};
class queue{
     public:
       Node*front;
       Node*rear;
    queue(){
        front=rear=NULL;
    }
    void enqueue(string name){
        Node*newNode=new Node(name);
        if(front==NULL){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
            rear->next=front;
        }
    }
    void dequeue(){
        if(front==NULL){
            cout<<"queue is empty";
        }
        else{
            Node*temp=front;
            front=front->next;
            delete temp;
            rear->next=front;
        }
    }
    void display(){
        if(front==NULL){
            cout<<"queue is empty";
        }
        else{
            Node*temp=front;
            while(temp!=rear){
                cout<<temp->name<<" ";
                temp=temp->next;
            }
        }
    }
};
int main(){
    queue q;
    int choice;
    string name;
    do{
        cout<<"-----MENU-----\n1.enqueue.\n2.dequeue.\n3.display.\n4.exit.\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
              cout<<"Enter name:";
              cin>>name;
              q.enqueue(name);
              break;
            case 2:
             q.dequeue();
             break;
            case 3:
              q.display();
              break;
            case 4:
               cout<<"Exiting..";
            default:
             cout<<"Enter valid choice";
             break;
        }
    }while(choice!=4);
}