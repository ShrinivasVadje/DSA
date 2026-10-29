#include<iostream>
using namespace std;
class Node{
   public:
   Node*next;
   string data;
   int pos;
   Node(string name,int p=0){
      data=name;
      next=NULL;
      pos=p;
   }
};
class queue{
    public:
      Node*front;
    queue(){
        front=NULL;
    }
   void enqueue(string name,int p){
             Node*newNode=new Node( name, p);
             if(front==NULL || front->pos>p){
                newNode->next=front;
                front=newNode;
             }
             else{
                Node*temp=front;
                while(temp->next!=NULL && p>=temp->next->pos ){
                   temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=temp->next->next;
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
      }
   }
   void display(){
      if(front==NULL){
         cout<<"queue is empty";
      }
      else{
         Node*temp=front;
         while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
         }
      }
   }
};
int main(){
    queue q;
    int choice,pos;
    string name;
    do{
        cout<<"-----MENU-----\n1.enqueue.\n2.dequeue.\n3.display.\n4.exit.\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
              cout<<"Enter name:";
              cin>>name;
              cout<<"Enter position";
              cin>>pos;
              q.enqueue(name,pos);
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
