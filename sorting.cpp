#include<iostream>
using namespace std;
void display(int n,string name[],int salary[]){
     for(int i=0;i<n;i++){
        cout<<"\nName:"<<name[i]<<" Salary:"<<salary[i];
     }
}
void bubble(int n,string name[],int salary[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
               if(salary[j]>salary[j+1]){
                swap(salary[j],salary[j+1]);
                swap(name[j],name[j+1]);
               }
        }
    }
}
void selection(int n,string name[],int salary[]){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(salary[min]>salary[j]){
                min=j;
            }
        }
        swap(salary[i],salary[min]);
        swap(name[i],name[min]);
    }
}
void insertion(int n,string name[],int salary[]){
    for(int i=1;i<n;i++){
        int curr=salary[i];
        int j=i-1;
        while(j>=0 && curr>salary[j]){
            swap(salary[j+1],salary[j]);
        swap(name[j+1],name[j]);
        }
        curr=salary[j+1];

    }
}
int main(){
    int max=100;
    string name[max];
    int salary[max];
    int n;
    cout<<"Enter how many emplyee:";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"name:";
        cin>>name[i];
        cout<<"salary";
        cin>>salary[i];
    }
    insertion(n,name,salary);
    display(n,name,salary);
}