#include<iostream>
using namespace std;
class student{
   public:
      int roll;
      string name;
      student*left;
      student*right;
      student(int r,string n){
        roll=r;
        name=n;
        left=right=NULL;
      }
};
class BST{
  student*root;
  student*insert(student*node,int roll,string name){
    if(!node){
      return new student(roll,name);
    }
    else if(roll<node->roll){
      node->left=insert(node->left,roll,name);
    }
    else if(roll>node->roll){
      node->right=insert(node->right,roll,name);
    }
    else{
      cout<<"DUplicate number not allowed";
    }
    return node;
  }
  student* search(student*node,int roll){
        if(!node || node->roll==roll){
          return node;
        }
         else if(roll<node->roll){
      return search(node->left,roll);
    }
    else if(roll>node->roll){
      return search(node->right,roll);
    }
  }
  student*findmin(student*node){
    while(node && node->left){
      node=node->left;
    }
    return node;
  }
  student*deletenode(student*node,int roll){
    if(!node){
      return node;
    }
     else if(roll<node->roll){
      node->left= deletenode(node->left,roll);
    }
    else if(roll>node->roll){
      node->right= deletenode(node->right,roll);
    }
    else{
      if(node->left==NULL){
        student*temp=node->right;
        delete node;
        return temp;
      }
      else if(node->right==NULL){
        student*temp=node->left;
        delete node;
        return temp;
      }
      else{
        student*temp=findmin(node->right);
        node->roll=temp->roll;
        node->name=temp->name;
        node->right=deletenode(node->right,temp->roll);
      }
    }
  }
  void inorder(student*node){
    if (node == NULL) return;
    inorder(node->left);
    cout<<node->roll<<"->";
    inorder(node->right);
  }
  void postorder(student*node){
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->roll<<"->";
  }
  void preorder(student*node){
    if (node == NULL) return;
     cout<<node->roll<<"->";
     preorder(node->left);
     preorder(node->right);
  }
  public:
  BST(){
    root=NULL;
  }
     void instertstudent(int roll,string name){
        root= insert(root,roll,name);
     }
     void searchnode(int roll){
      student*s=search(root,roll);
      if(s){
        cout<<"Found name:"<<s->name;
      }
      else{
        cout<<"Not found";
      }
     }
     void deletee(int roll){
      root=deletenode(root,roll);
     }
     void displayinorder(){
      cout<<"inorder:";
      inorder(root);
     }
     void displaypreorder(){
      cout<<"inorder:";
      preorder(root);
     }
     void displaypostorder(){
      cout<<"inorder:";
      postorder(root);
     }
     void displaylevelorder(){
              if(!root){
                return;
              }
              else {
                student* arr[100];
                int front=0,rear=0;
                  arr[rear++]=root;
                  cout<<"level order:";
                while(front<rear){
                    student*curr=arr[front++];
                    cout<<"studnet name:"<<curr->name<<" student roll:"<<curr->roll;
                    if(curr->left){
                      arr[rear++]=curr->left;
                    }
                    if(curr->right){
                      arr[rear++]=curr->right;                    }
                }
              }
    }
};
 int main(){
  BST b;
  int choice,roll;
  string name;
  do{
    cout<<"\n1.insert\n2.search\n3.delete\n4.inorder\n5.postorder\n6.preorder.\n7levelorder.\n8exit";
    cin>>choice;
    switch(choice){
      case 1:
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter roll";
        cin>>roll;
        b.instertstudent(roll,name);
        break;
      case 2:
         cout<<"Enter roll";
         cin>>roll;
         b.searchnode(roll);
         break;
        case 3:
         cout<<"Enter roll";
         cin>>roll;
         b.deletee(roll);
         break;
        case 4:
          b.displayinorder();
          break;
        case 5:
         b.displaypostorder();
         break;
        case 6:
         b.displaypreorder();
         break;
        case 7:
         b.displaylevelorder();
         break;
        case 8:
         cout<<"Exiting";
         break;
        default:
          cout<<"Enter valid choice";
          break;
         
         
    }
  }while(choice!=8);
 }