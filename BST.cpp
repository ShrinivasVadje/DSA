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
    private:
    student*root;
    student*insert(student*node,string name,int roll){
          if(node==NULL){
             return new student(roll,name);
          }
          else if(node->roll>roll){
            node->left=insert(node->left,name,roll);
          }
          else if(node->roll<roll){
            node->right=insert(node->right,name,roll);
          }
          else{
            cout<<"Duplicate roll number is not allowed";
          }
    }
   student*search(student*node,int roll){
          if(node==NULL || node->roll==roll ){
            return node;
          }
          else if(roll<node->roll){
            node->left=search(node->left,roll);
        }
         else if(roll>node->roll){
            node->right=search(node->right,roll);
         }
   }
   student*findmin(student*node){
     while(node==NULL && node->left==NULL){
        node=node->left;
     }
     return node;
   }
   student*deletenode(student*node,int roll){
       if(node==NULL){
        return node;
       }
       else if(roll<node->roll){
        node->left=deletenode(node->left,roll);
       }
       else if(roll>node->roll){
        node->right=deletenode(node->right,roll);
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
    if(node!=NULL){
        inorder(node->left);
        cout<<node->roll<<"->";
        inorder(node->right);
    }
   }
   void postorder(student*node){
    postorder(node->left);
    postorder(node->right);
    cout<<node->roll<<"->";  

   }
    
};