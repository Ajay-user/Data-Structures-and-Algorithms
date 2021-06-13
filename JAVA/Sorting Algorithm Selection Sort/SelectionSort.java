class SelectionSort {

// utility funtion for finding the minimum position
  public int getMinimumPostion(int arr[], int start, int stop){
    int min = start;
    for(int i=start; i<stop; i++){
      if(arr[i]<arr[min]){
        min = i;
      }
    }
    return min;
  }

// utility function for swapping array elements
  public void swapPosition(int arr[], int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1]=arr[pos2];
    arr[pos2]=temp;
 }

// iterative version of selection sort
  public void sortIterative(int arr[], int stop){
    int min;
    for(int pos=0; pos<stop; pos++){
      min =getMinimumPostion(arr, pos, stop);
      if(pos!=min){
        swapPosition(arr, pos, min);
      }
    }
  }

// recursive version of selection sort
 public void sortRecursive(int arr[], int start, int stop){
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

  public void printArray(int[] arr) {
      for (int i : arr) {
          System.out.print(" [" + i + "] ");
      }
  }



  public static void main(String[] args) {
    System.out.println("\nSelection Sort!\n");

  // create an instance
    SelectionSort obj = new SelectionSort();

  // working array
    int arr1[] = { 9, 1, 8, 2, 7, 3, 4, 6, 5, 0};
    obj.printArray(arr1);
    int len = arr1.length;
    obj.sortIterative(arr1, len);
    System.out.println("\n\nAfter sorting\n");
    obj.printArray(arr1);

    System.out.println("\n\nSelection Sort!\n");
  // working array
    int arr2[] = { 3, 5, 8, 2, 0, 9, 4, 6, 1, 7};
    obj.printArray(arr2);
    len = arr2.length;
    obj.sortRecursive(arr2, 0, len);
    System.out.println("\n\nAfter sorting\n");
    obj.printArray(arr2);








  }
}