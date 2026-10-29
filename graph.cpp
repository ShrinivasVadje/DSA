#include<iostream>
#include<string>
using namespace std;
class city{
      public:
        int n;
        string cityname[10];
        int adjmatrix[10][10];
        int adjlist[10][10];
        int listsize[10];
        city(int city){
            n=city;
            for(int i=0;i<n;i++){
                listsize[i]=0;
                for(int j=0;j<n;j++){
                    adjmatrix[i][j];
                }
            }
        }
        void setcityname(int i,string name){
           cityname[i]=name;
        }
        void joined(int u,int v){
            adjmatrix[u][v]=1;
            adjmatrix[v][u]=1;
            adjlist[u][listsize[u]++]=v;
            adjlist[v][listsize[v]++]=u;
        }
        void displayadjmatrix(){
            for(int i=0;i<n;i++){
                cout<<cityname[i][0]<<endl;
            }
            for(int i=0;i<n;i++){
                cout<<cityname[i][0]<<":";
                for(int j=0;j<n;j++){
                    cout<<adjmatrix[i][j];
                }
            }
        }
        void displayadjlist(){
            for(int i=0;i<n;i++){
                cout<<cityname[i]<<"->";
                for(int j=0;j<listsize[i];j++){
                      cout<<cityname[adjlist[i][j]];
                }
            }
        }
        void bfs(int start){
            int top=-1;
            int stack[10];
            int visited[10]={0};
            cout<<"bfs is starting from:"<<stack[start];
            stack[++top]=start; 
            while(top>-1){
                int node=stack[top--];
                if(!visited[node]){
                    cout<<cityname[node];
                    visited[node]=1;
                }
            }
     }
};
int main(){

}