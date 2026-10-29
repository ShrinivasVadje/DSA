#include<iostream>
#include<string>
using namespace std;
class array{
    public:
    string arr[10];
    int top;
    array(){
       top=-1;
    }
    void push(string url){
        if(top>=10){
             cout<<"Stack is full";
        }
        else{
            arr[++top]=url;
            cout<<"Visited";
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        else{
            cout<<"going back"<<arr[top];
            top--;
        }
    }
    void peak(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        else{
            cout<<"now yoou are at:"<<arr[top];
        }
    }
    void display(){
        if(top==-1){
            cout<<"Stack is empty";
        }
        else{
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
    }
};
class Node{
    public:
    string url;
    Node*next;
     Node(string x){
        url=x;
        next=NULL;
     }
};
class list{
    public:
    Node*top;
    list(){
    top=NULL;
    }   
    void push(string url){
        Node*newNode=new Node(url);
        newNode->next=top;
        top=newNode;
    }
    void pop(){
        if(top==NULL){
            cout<<"No url";
        }
        else{
            Node*temp=top;
            top=top->next;
            delete temp;
        }
    }
    void peak(){
        if(top==NULL){
            cout<<"No url";
        }
        else{
            cout<<"You are at:"<<top->url;
        }
    }
    void display(){
         if(top==NULL){
            cout<<"No url";
        } else{
            Node*temp=top;
            while(temp!=NULL){
                cout<<temp->url<<"->";
                temp=temp->next;
            }
        }
    }

};
int main(){
    int choice,type;
    string url;
    array a;
    list l;
   cout<<"Enter type(1.array,2.linklist):";
    cin>>type;
    if(type==1){
      do{
        cout<<"\n-----Menu-----\n1.Visit newpage.\n2.Go back.\n3.show page.\n4.show history.\n5Exit";
        cin>>choice;
        switch(choice){
            case 1:
               cout<<"Enter url:";
               cin>>url;
              a.push(url);
              break;
            case 2:
              a.pop();
              break;
            case 3:
              a.peak();
              break;
            case 4:
              a.display();
              break;
            case 5:
              cout<<"Exiting";
              break;
            default:
              cout<<"Enter valid choice";
              break;
        }
      }while(choice!=5);
    }
    else if(type==2){
        do{
        cout<<"\n-----Menu-----\n1.Visit newpage.\n2.Go back.\n3.show page.\n4.show history.\n5Exit";
        cin>>choice;
        switch(choice){
            case 1:
               cout<<"Enter url:";
               cin>>url;
              l.push(url);
              break;
            case 2:
              l.pop();
              break;
            case 3:
              l.peak();
              break;
            case 4:
              l.display();
              break;
            case 5:
              cout<<"Exiting";
              break;
            default:
              cout<<"Enter valid choice";
              break;
        }
      }while(choice!=5);
    }
    else{
        cout<<"Enter a valid type";
    }

}