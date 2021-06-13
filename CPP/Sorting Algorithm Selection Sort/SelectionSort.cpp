#include <iostream>

using namespace std;


// utility funtion for finding the minimum position
int getMinimumPostion(int arr[], int start, int stop){
  int min = start;
  for(int i=start; i<stop; i++){
    if(arr[i]<arr[min]){
      min = i;
    }
  }
  return min;
}

// utility function for swapping array elements
void swapPosition(int arr[], int pos1, int pos2){
  int temp = arr[pos1];
  arr[pos1]=arr[pos2];
  arr[pos2]=temp;
}

// iterative version of selection sort
void sortIterative(int arr[], int stop){
  int min;
  for(int pos=0; pos<stop; pos++){
    min =getMinimumPostion(arr, pos, stop);
    if(pos!=min){
      swapPosition(arr, pos, min);
    }
  }
}

// recursive version of selection sort
void sortRecursive(int arr[], int start, int stop){
  if(start<stop){
    int min = getMinimumPostion(arr, start, stop);
    if(start!=min){
      swapPosition(arr, start, min);
    }
    // recursive call
    sortRecursive(arr, start+1, stop);
  }
}



// function to print array elements
void printArray(int arr[], int len){
  cout << "\n Array elements \n";
  for(int i=0; i<len; i++){
    cout << arr[i] <<'\t';
  }
}



int main() {
  cout << "\n \t\t\t\t\tSelection Sort!\n";

// working array
  int arr[]={5,4,3,2,1};

  int len = sizeof(arr)/sizeof(int);
  cout <<"length of array is "<<len<<'\n';

  printArray(arr, len);
// Iterative selection sort version
  sortIterative(arr, len);
  printArray(arr, len);
  cout<<"After sorting \n";

// working array
  int arr_1[] = {4,3,5,2,1};

  len =  sizeof(arr)/sizeof(int);
  cout <<"length of array is "<<len<<'\n';

  printArray(arr_1, len);
// Recursive selection sort version
  sortRecursive(arr_1, 0, len);
  printArray(arr_1, len); 
  cout<<"After sorting \n";
}