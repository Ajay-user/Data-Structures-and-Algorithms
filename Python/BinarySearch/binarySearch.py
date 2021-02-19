import math

def binarySearchRecursive(arr,searchElem, start,stop):
    result = -1;
    if (stop >= start):
        mid = math.floor((start+stop)/2)
        if(arr[mid]==searchElem):
            result = mid
        elif(arr[mid]>searchElem):
           result = binarySearchRecursive(arr, searchElem, start, mid-1)
        else:
           result = binarySearchRecursive(arr, searchElem, mid+1, stop)
    
    return result;


def binarySearchIterative(arr, searchElem, start, stop):
    result = -1
    while(stop >= start):
        mid = math.floor((start+stop)/2)
        if(arr[mid] == searchElem):
            return mid
        elif(arr[mid] > searchElem):
            stop = mid-1
        else:
            start = mid+1
    return result


def findFirstOccurrence(arr, searchElem, start, stop):
    result = -1
    while(stop >= start):
        mid = math.floor((start+stop)/2)
        if(arr[mid] == searchElem):
            result = mid
            stop = mid-1
        elif(arr[mid] > searchElem):
            stop = mid-1
        else:
            start = mid+1
    return result

def findLastOccurrence(arr, searchElem, start, stop):
    result = -1
    while(stop >= start):
        mid = math.floor((start+stop)/2)
        if(arr[mid] == searchElem):
            result = mid
            start = mid+1
        elif(arr[mid] > searchElem):
            stop = mid-1
        else:
            start = mid+1
    return result




def print_result(result):
    if result!= -1:
        print("element found at position  ",result)
    else:
        print("element not found")
        



    # sorted array
arr = [1,2,3,4,5,6,7,8,9]
search_item = 4
start = 0
stop = len(arr) - 1



result = binarySearchRecursive(arr, search_item, start, stop)
print_result(result)

result = binarySearchIterative(arr, search_item, start, stop)
print_result(result)


# find first occurrence and last occurrence in a sorted array with duplicates 
sortedArray = [1,1,2,2,3,3,3,3,4,4,4,4,5,5,5,5,5,5,6,6,6,6,7,7,7,7,7]
search_item = 3
start = 0
stop = len(sortedArray) - 1

first = findFirstOccurrence(sortedArray, search_item, start, stop)
last = findLastOccurrence(sortedArray, search_item, start, stop)
print('first occurrence is at ',first,'last occurrence is at ',last,'total number of occurrence is',last-first+1)