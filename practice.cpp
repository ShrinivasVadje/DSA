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
    void insert(int val){
        Node*newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            Node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;

        }

    }
 void search(int key){
    if(head==NULL){
        cout<<"list is empty";
    }
    else{
        Node*temp=head;
        int f=0,i=1;
        while(temp!=NULL){
            if(temp->data==key){
                cout<<"key found at index:"<<i;
                f=1;
                break;  
            }
            temp=temp->next;
            i++;
        }
        if(f==0){
            cout<<"key not found";
        }
    }
 }
 void traverse(){
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
 void deletenode(int key){
    if(head==NULL){
        cout<<"List is empty";
    }
    else if(head->data==key){
        Node*temp=head;
        head=head->next;
        delete temp;
        cout<<"deleted";
    }
    else{
    Node*temp=head;
        while(temp!=NULL && temp->next->data!=key){
            temp=temp->next;
        }
        if(temp->next){
            Node*curr=temp->next;
            temp->next=temp->next->next;
            delete curr;
            cout<<"deleted";
        }
       else{
        cout<<"not found";
       }
    }
    }
 void sort(){
    if(head==NULL){
        cout<<"List is empty";
    }
    else if(head->next==NULL){
        cout<<"sorted";
    }
    else{
        for(Node*i=head;i!=NULL;i=i->next){
            for(Node*j=head;j->next!=NULL;j=j->next){
                if(j->data>j->next->data){
                     swap(j->data,j->next->data);
                }
            }
        }
    }
 }
 void concatination(list & other){
    if(head==NULL){
        head=other.head;
    }
    else{
        Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
       temp->next=other.head;
       other.head=NULL;
       cout<<"Done";
    }
 }
};
int main(){
    list l,l1;
    int i,x;
    do{
        cout<<"\n----Menu----\n1.insert.\n2.search.\n3.delete.\n4.sort.\n5.concatinate\n6.display.\n7.exit\nEnter Choice:";
        cin>>i;
        switch(i){
           case 1:
              cout<<"Enter value";
              cin>>x;
            l.insert(x);
            break;
            case 2:
            cout<<"Enter value";
              cin>>x;
            l.search(x);
            break;
            case 3:
            cout<<"Enter value";
              cin>>x;
            l.deletenode(x);
             break;
            case 4:
              l.sort();
              break;
            case 5:
            cout<<"Enter Value(-1 to exit):";
              do{
                cin>>x;
                l1.insert(x);
              }while(x!=-1);
              l.concatination(l1);
              break;
            case 6:
              l.traverse();
              break;
            case 7:
              cout<<"Exiting";
              break;
            default:
               cout<<"Enter vaalid choice";
             break;
            }
    }while(i!=7);
}