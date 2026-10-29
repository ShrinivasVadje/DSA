#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node*next;
       Node(int val){
              data=val;
              next=NULL;
       }
};
class list{
    public:
        Node*head;
        Node*tail;
        list(){
            head=tail=NULL;
        }
    void pushfront(int val){
        Node*newNode=new Node(val);
        if(head==NULL){
              head=tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void pushback(int val){
        Node*newNode=new Node(val);
        if(head==NULL){
              head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    void print(){
        if(head==NULL){
            cout<<"list is empty";
        }
        else{
            Node*temp=head;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
    }
  void insertion(int val,int pos){
      Node*newNode=new Node(val);
      Node*temp=head;
      for(int i=1;i<pos-1;i++){
        temp=temp->next;
      }
    newNode->next=temp->next;
    temp->next=newNode;

  }
};
int main(){
    list l;
    l.pushfront(1);
    l.pushfront(3);
    l.insertion(4,2);
    l.print();
}
