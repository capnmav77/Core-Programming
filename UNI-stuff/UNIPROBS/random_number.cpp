#include<iostream>
#include<cstdlib>

using namespace std ;

void bubbleSort(int array[], int size) {
    
  // loop to access each array element
  for (int step = 0; step < (size-1); step++) {
      
    // check if swapping occurs
    int swapped = 0;
    
    // loop to compare two elements
    for (int i = 0; i < (size-step-1); i++) {
        
      // compare two array elements
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = 1;
      }
    }
    // no swapping means the array is already sorted
    // so no need of further comparison
    if (swapped == 0)
      break;
  }
}

int main(){
    int *arr,n;
    cout<<"enter the size of the array"<<endl;
    cin>> n;
    arr =(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    bubbleSort(arr,n);
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}