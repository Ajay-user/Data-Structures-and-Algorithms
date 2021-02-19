#include <iostream>

using namespace std;

// binary search recursive version
int searchRecursive(int arr[], int k, int left, int right)
{

    if (right >= left)
    {

        int mid = (left + right) / 2;
        cout << "looking at location -- " << mid << "\n";
        if (arr[mid] == k)
        {
            return mid;
        }

        else
        {
            if (arr[mid] > k)
            {
                return searchRecursive(arr, k, left, mid - 1);
            }
            else
            {
                return searchRecursive(arr, k, mid + 1, right);
            }
        }
    }

    return -1;
}

// binary search iterative version
 int searchIterative(int arr[],int k,int start, int stop){

        int result = -1;
        int mid;
        

        while(stop >= start){

            mid = (start + stop)/2;
            cout << "looking at location -- " << mid << "\n";
            if(arr[mid]==k){
            result = mid;
            }
            else{
                if(arr[mid]>k){
                    stop=mid-1;
                }
                else{
                    start=mid+1;
                }

            }

          }
          return result;

 }

int findFirstOccurrence(int arr[],int start,int stop,int k){
int result=-1;
    while(start<=stop){
        int mid = (start+stop)/2;
        if(arr[mid]==k){
            result=mid;
            stop=mid-1;
        }
        else if(arr[mid]>k){
            stop=mid-1;
        }
        else{
            start=mid+1;
        }
    }
return result;
 }


int findLastOccurrence(int arr[],int start,int stop,int k){
int result=-1;
while(start<=stop){
    int mid = (start+stop)/2;
    if(arr[mid]==k){
        result=mid;
        start=mid+1;
    }
    else if(arr[mid]>k){
        stop=mid-1;
    }
    else{
        start=mid+1;
    }
}return result;
 }

int findNumberOfOccurrence(int arr[],int start,int stop,int k,bool flag){
int result=-1;
while(start<=stop){
    int mid = (start+stop)/2;
    if(arr[mid]==k){
        result=mid;
        if(flag){
            stop=mid-1;
        }else{
        start=mid+1;
        }
    }
    else if(arr[mid]>k){
        stop=mid-1;
    }
    else{
        start=mid+1;
    }
}return result;
 }

int main()
{

    cout << "BINARY SEARCH RECURIVE VERSION!" << endl;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int stop = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int searchItem = 11;

    int result = searchRecursive(arr, searchItem, start, stop-1);
    cout << "result found at location -->> " << result<<endl;


    cout << "BINARY SEARCH ITERATIVE VERSION!" << endl;
    result = searchIterative(arr, searchItem , start, stop);
    cout << "result found at location -->> " << result<<endl;



    cout<<"------SORTED ARRAY WITH DUPLICATE------- "<<endl;

    int sortedArrayWithDuplicates[]={1,1,2,2,3,3,3,3,4,4,4,4,5,5,5,5,5,5,6,6,6,6,7,7,7,7,7};
    int len= sizeof(sortedArrayWithDuplicates)/sizeof(sortedArrayWithDuplicates[0]);
    int searchElement=5;

    int firstOccurrence = findFirstOccurrence(sortedArrayWithDuplicates,start,len-1,searchElement);
    int lastOccurrence = findLastOccurrence(sortedArrayWithDuplicates,start,len-1,searchElement);

    int first=findNumberOfOccurrence(sortedArrayWithDuplicates,start,len-1,searchElement,true);

    if(first!=-1){
            int last=findNumberOfOccurrence(sortedArrayWithDuplicates,start,len-1,searchElement,false);
         cout<<"number of occurrence is "<<(last-first+1)<<endl;
         cout<<"first occurrence is at "<<firstOccurrence<<endl;
         cout<<"last occurrence is at "<<lastOccurrence<<endl;
    }

    return 0;
}
