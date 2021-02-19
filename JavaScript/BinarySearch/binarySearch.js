const binarySearchRecursive = (arr, searchElem, start, stop) => {
  let mid;
  if (stop >= start) {
    mid = Math.floor((start + stop) / 2);
    if (arr[mid] == searchElem) {
      return mid;
    } else {
      if (arr[mid] > searchElem) {
        return binarySearchRecursive(arr, searchElem, start, mid - 1);
      } else {
        return binarySearchRecursive(arr, searchElem, mid + 1, stop);
      }
    }
  }
  return -1;
};

const binarySearchIterative = (arr, searchElem, start, stop) => {
  let mid;
  while (stop >= start) {
    mid = Math.floor((start + stop) / 2);
    if (arr[mid] == searchElem) {
      return mid;
    } else {
      if (arr[mid] > searchElem) {
        stop = mid - 1;
      } else {
        start = mid + 1;
      }
    }
  }
  return -1;
};

const firstOccurrence = (arr, searchElem, start, stop) => {
  let mid,
    result = undefined;
  while (stop >= start) {
    mid = Math.floor((start + stop) / 2);
    if (arr[mid] == searchElem) {
      result = mid;
      stop = mid - 1;
    } else {
      if (arr[mid] > searchElem) {
        stop = mid - 1;
      } else {
        start = mid + 1;
      }
    }
  }
  return result;
};

const lastOccurrence = (arr, searchElem, start, stop) => {
  let mid,
    result = undefined;
  while (stop >= start) {
    mid = Math.floor((start + stop) / 2);
    if (arr[mid] == searchElem) {
      result = mid;
      start = mid + 1;
    } else {
      if (arr[mid] > searchElem) {
        stop = mid - 1;
      } else {
        start = mid + 1;
      }
    }
  }
  return result;
};

const printResult = (result) => {
  if (result != -1) {
    console.log("found at loction", result);
  } else {
    console.log("element not found");
  }
};

const sortedArray = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let start = 0;
let stop = sortedArray.length - 1;
let searchElem = 9;
let result;

// recursive version
result = binarySearchRecursive(sortedArray, searchElem, start, stop);
printResult(result);

//iterative version
result = binarySearchIterative(sortedArray, searchElem, start, stop);
printResult(result);

console.log("Array with duplicates -- find first and last occurrence");
const sortedArrayWithDuplicates = [3, 3, 3, 4, 4, 4, 4, 5, 5, 5];
start = 0;
stop = sortedArrayWithDuplicates.length - 1;
searchElem = 3;

// first occurrence
let first = firstOccurrence(sortedArrayWithDuplicates, searchElem, start, stop);
let last = lastOccurrence(sortedArrayWithDuplicates, searchElem, start, stop);
if (first != undefined) {
  console.log(
    "first occurrence is at",
    first,
    "last occurrence is at",
    last,
    "total number of occurrence",
    last - first + 1
  );
} else {
  console.log("element not found");
}
