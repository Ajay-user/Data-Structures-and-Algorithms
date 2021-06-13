// utility funtion for finding the minimum position
const getMinimumPostion=(arr, start, stop)=>{
  min=start;
  for(let i=start; i<stop; i++){
    if(arr[i]<arr[min]){
      min = i;
    }
  }

  return min
}

// utility function for swapping array elements
const swapPosition = (arr, pos1, pos2)=>{
  let temp = arr[pos1];
  arr[pos1]=arr[pos2];
  arr[pos2]=temp;
  return arr
}

// iterative version of selection sort
const sortIterative = (arr, stop)=>{
  let min;
  for(let pos=0; pos<stop; pos++){
    min = getMinimumPostion(arr, pos, stop);
    if(pos!=min){
      arr = swapPosition(arr, pos, min);
    }
  }
  return arr;
}


// recursive version of selection sort
const sortRecursive=(arr, start, stop)=>{
  if(start<stop){
    let min = getMinimumPostion(arr, start, stop);
    if(start!=min){
      arr = swapPosition(arr, start, min);
    }
    // recursive call
    return sortRecursive(arr, start+1, stop);
  }else{
    return arr
  }
}


// function to print array elements
const printArray=(arr, len)=>{
  console.log("\n Array elements \n");
  for(let i=0; i<len; i++){
    console.log("\t",arr[i]);
  }
}


console.log('Selection Sort Eg#1 \n');
// working array
let arr=[5,4,3,2,1];
console.log('\t\tBefore sorting')
printArray(arr,arr.length);

// Iterative selection sort version
arr = sortIterative(arr, arr.length);
console.log('\t\tAfter sorting')
printArray(arr, arr.length);

// **********************************

console.log('Selection Sort Eg#2 \n');
// working array
arr=[3,1,5,2,4];
console.log('\t\tBefore sorting')
printArray(arr,arr.length);

// Iterative selection sort version
arr = sortRecursive(arr, 0 ,arr.length);
console.log('\t\tAfter sorting')
printArray(arr, arr.length);