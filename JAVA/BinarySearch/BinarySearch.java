

public class BinarySearch {

    public int searchRecursive( int[] arr, int searchElem, int l, int r) {
        if (r >= l) {

            int mid = (l + r) / 2;
            System.out.println("looking at location " + mid);
            if (arr[mid] == searchElem) {
                return mid;
            } else {
                if (arr[mid] > searchElem) {
                    return searchRecursive(arr,searchElem,  l, mid - 1);
                } else {
                    return searchRecursive(arr,searchElem, mid + 1, r);
                }
            }
        }
        return -1;

    }

    public int searchIterative(int[] arr, int searchElem,int start, int stop) {
        int result = -1;
        int mid;
        while (stop>=start) {

            mid = (start + stop) / 2;
            
            if (arr[mid] == searchElem){
                result = mid;
                return result;
            } else {
                if (arr[mid] > searchElem) {
                    stop = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return result;
    }

    public int findFirstOccurrenceIterative(int[] arr, int searchElem, int start, int stop) {

        int result = -1;
        while (start <= stop) {
            int mid = (start + stop) / 2;
            if (arr[mid] == searchElem) {
                result = mid;
                stop = mid - 1;
            } else if (arr[mid] > searchElem) {
                stop = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }

    public int findlastOccurrenceIterative(int[] arr, int searchElem, int start, int stop) {

        int result = -1;
        while (start <= stop) {
            int mid = (start + stop) / 2;
            if (arr[mid] == searchElem) {
                result = mid;
                start = mid + 1;
            } else if (arr[mid] > searchElem) {
                stop = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }

    public int findNumberOfOccurrenceIterative(int[] arr, int searchElem, int start, int stop, boolean flag) {
        int result = -1;
        while (start <= stop) {
            int mid = (start + stop) / 2;
            if (arr[mid] == searchElem) {
                result = mid;
                if (flag) {
                    stop = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (arr[mid] > searchElem) {
                stop = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }

    public void displayOutput(int result) {
        if (result != -1) {
            System.out.println("found at location " + result);
        } else {
            System.out.println("element not found in the array");
        }
    }

    public static void main(String[] args) {
        int[] sortedArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int result;
        int searchItem = 9;
        int start = 0;
        int stop = sortedArray.length - 1;

        BinarySearch search = new BinarySearch();

        result = search.searchRecursive( sortedArray, searchItem, start, stop);
        search.displayOutput(result);

        result = search.searchIterative(sortedArray, searchItem, start, stop);
        search.displayOutput(result);

        int[] sortedArrayWithDuplicates = { 1, 1, 3, 3, 5, 5, 5, 5, 5, 7, 8, 8, 8, 9, 9, 9, 9, 9 };
        int findElement = 3;
        int len = sortedArrayWithDuplicates.length;
        int firstOccurrence = search.findFirstOccurrenceIterative(sortedArrayWithDuplicates, findElement, start,
                len - 1);
        int lastOccurrence = search.findlastOccurrenceIterative(sortedArrayWithDuplicates, findElement, start, len - 1);

        int first = search.findNumberOfOccurrenceIterative(sortedArrayWithDuplicates, findElement, start, len - 1,
                true);
        if (first != -1) {
            int last = search.findNumberOfOccurrenceIterative(sortedArrayWithDuplicates, findElement, start, len - 1,
                    false);
            System.out.println("number of occurrence is " + (last - first + 1));
        }
        System.out.println("first occurrence is " + firstOccurrence);
        System.out.println("last occurrence is " + lastOccurrence);
    }
}