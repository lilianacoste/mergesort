#include <iostream>
#include <cstdlib> //for random functions
#include <ctime> //for time function

//merge function
void merge(int *arr, int left, int mid, int right){
    int arr1 = mid - left + 1; 
    int arr2 = right - mid;
    //create temp arrays to store elements of subarrays. Dyamically allocate by using new kewyword.
    int *leftArr = new int[arr1];
    int *rightArr = new int[arr2];
    //copy elements from original array to temp arrays
    for (int i = 0; i < arr1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < arr2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    //temp variables to traverse left and right subarrays
    int i = 0;
    int j = 0;
    int k = left;
    //merge temp arrays back into original array
    while (i < arr1 && j < arr2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    //copy remaining elements of leftArr
    while (i < arr1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    //copy remaining elements of rightArr
    while (j < arr2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    //free memory allocated for temp arrays
    delete[] leftArr;
    delete[] rightArr;
}
//Merge sort function
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
//print array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
 std::srand(std::time(0));  //ensure random numbers are generated each time
    int size; //prompt for size of array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    int *array = new int[size]; //allocate memory for array
    for (int i = 0; i < size; i++) {
        array[i] = std::rand() % 100; //fill array with random numbers
    }
    //callmergeSort function
    mergeSort(array, 0, size - 1);
    //print array
    std::cout << "Sorted array: ";
    printArray(array, size);
    delete[] array; //free memory
    return 0;
}