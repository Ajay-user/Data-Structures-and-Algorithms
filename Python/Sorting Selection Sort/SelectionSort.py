# utility funtion for finding the minimum position
def getMinimumPostion(arr, start, stop):
  min = start;
  for i in range(start,stop):
    if arr[i]<arr[min]:
      min = i;

  return min;


# utility function for swapping array elements
def swapPosition( arr, pos1, pos2):
  temp = arr[pos1];
  arr[pos1]=arr[pos2];
  arr[pos2]=temp;
  return arr;



# iterative version of selection sort
def sortIterative(arr, stop):
  for pos in range(stop):
    min = getMinimumPostion(arr, pos, stop);
    if pos!=min:
      arr = swapPosition(arr, pos, min);
  
  return arr


# recursive version of selection sort
def sortRecursive(arr,  start, stop):
  if start<stop:
    min = getMinimumPostion(arr, start, stop);
    if start!=min:
      arr =  swapPosition(arr, start, min)

    #recursive call
    return sortRecursive(arr, start+1, stop);
  else:
    return arr



# function to print array elements
def printArray(arr):
  for el in arr:
    print('[',el,']',end='\t')


print('Selection Sort')

# working array
arr = [5,4,3,2,1]
printArray(arr)

arr = sortIterative(arr, len(arr))
print('Before sorting')
printArray(arr)
print('After sorting')


# **********************************

print('Selection Sort')

# working array
arr = [2,3,4,5,1]
printArray(arr)

arr = sortRecursive(arr, 0, len(arr))
print('Before sorting')
printArray(arr)
print('After sorting')

