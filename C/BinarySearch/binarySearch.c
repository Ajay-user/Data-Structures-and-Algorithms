#include <stdio.h>
#include <stdlib.h>

int binary_search_recursive(int arr[], int search_ele, int start, int stop){
    int result = -1;
    if(stop>=start){
        int mid = (start+stop)/2;
        if(arr[mid]==search_ele){
            result = mid;
        }
        else{
            if(arr[mid]>search_ele){
                stop = mid-1;
                result = binary_search_recursive(arr, search_ele, start, stop);
            }
            else{
                start = mid+1;
                result = binary_search_recursive(arr, search_ele, start, stop);
            }
        }

    }
    return result;
}

int binary_search_iterative(int arr[], int search_ele, int start, int stop){
    int result = -1;

    while(stop >= start){

        int mid = (start+stop)/2;
        if(arr[mid]==search_ele){
            result = mid;
            return result;
        }
        else{
            if(arr[mid]>search_ele){
                stop = mid-1;
            }
            else{
                start = mid+1;
            }
        }
    }

    return result;

}


int find_first_occurrence(int arr[], int search_ele, int start, int stop){
    int result = -1;

    while(stop >= start){
         int mid = (start+stop)/2;
        if(arr[mid]==search_ele){
            result = mid;
            stop = mid - 1;
        }
        else{
            if(arr[mid]>search_ele){
                stop = mid-1;
            }
            else{
                start = mid+1;
            }
        }
    }
    return result;
}

int find_last_occurrence(int arr[], int search_ele, int start, int stop){
    int result = -1;

    while(stop >= start){
         int mid = (start+stop)/2;
        if(arr[mid]==search_ele){
            result = mid;
            start = mid + 1;
        }
        else{
            if(arr[mid]>search_ele){
                stop = mid-1;
            }
            else{
                start = mid+1;
            }
        }
    }
    return result;
}


void print_result(int result){
    if(result!=-1){
            printf( "result found at location -->> %d \n",result);
    }
    else
    {
            printf("element not found \n");
    }
}

int main()
{
    printf("Binary search on a sorted array!\n\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int searchItem = 5;
    int len = sizeof(arr) / sizeof(arr[0]);
    int stop = len - 1;
    int start = 0;
    // recursive version
    int result = binary_search_recursive(arr, searchItem, start, stop);
    print_result(result);

    // iterative search version
    result = binary_search_iterative(arr, searchItem, start, stop);
    print_result(result);


    printf("\n\n find first and last occurrence in a sorted array with duplicate elements \n\n");

    int sortedArrayWithDuplicates[]={1,1,2,2,3,3,3,3,4,4,4,4,5,5,5,5,5,5,6,6,6,6,7,7,7,7,7};
    int searchElement=5;
    start = 0;
    len = sizeof(sortedArrayWithDuplicates)/sizeof(sortedArrayWithDuplicates[0]);
    stop = len - 1;

    // find first occurrence
    printf("\n find first occurrence of the element %d \n",searchElement);
    result = find_first_occurrence(sortedArrayWithDuplicates, searchElement, start, stop);
    print_result(result);

    printf("\n find last occurrence  of the element %d \n",searchElement);
    result = find_last_occurrence(sortedArrayWithDuplicates, searchElement, start, stop);
    print_result(result);

    printf("\n Total occurrence  of the element %d \n",searchElement);
    int first = find_first_occurrence(sortedArrayWithDuplicates, searchElement, start, stop);
    int last = find_last_occurrence(sortedArrayWithDuplicates, searchElement, start, stop);
    result = last - first + 1;
    printf("total occurrence is %d",result);


    return 0;



}
