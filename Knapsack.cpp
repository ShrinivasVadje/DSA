#include<iostream>
#include<algorithm>
using namespace std;
int main(){
   int capacity,n;
   float p[100],w[100];
   float ratio[100],profit=0;
   cout<<"Enter the number of weights:";
   cin>>n;
  for(int i=0;i<n;i++){
      cout<<"Enter the weight of "<<i+1<<": ";
      cin>>w[i];
      cout<<"Enter the profit of "<<i+1<<": ";
      cin>>p[i];
    ratio[i]=p[i]/w[i];
}
   cout<<"Enter the capacity:";
   cin>>capacity;
for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
       if(ratio[i]<ratio[j]){
           swap(ratio[i],ratio[j]);
           swap(w[i],w[j]);
           swap(p[i],p[j]);
       
}
}
} 

for(int i=0;i<n;i++){
   if(capacity>=w[i]){
       capacity-=w[i];
       profit+=p[i];
}
else{
   profit+=ratio[i]*capacity;
   break;
}
}

cout<<"The maximum profit is: "<<profit;
return 0;
}