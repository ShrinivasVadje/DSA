#include<iostream>
using namespace std;
int main(){
    int i;
    int arr[7] = {2, 34, 12, 4, 5, 32, 56};  
    int max = arr[0];
    for(i = 1; i < 7; i++){  
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int smax=arr[0];
    for(i = 1; i < 7; i++){  
        if(arr[i] > smax && arr[i]!=max){
            smax = arr[i];
        }
    }


    cout << "The second largest number is = " << smax;
    
    return 0;
}
