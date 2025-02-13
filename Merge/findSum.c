#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of arr[].
void merge(int arr[], int left, int mid, int right) {
  // Find sizes of two subarrays to be merged
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temporary arrays L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Merge the temporary arrays back into arr[]
  int i = 0;     // Initial index of first subarray
  int j = 0;     // Initial index of second subarray
  int k = left;  // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Function to sort arr[] using merge sort
void merge_sort(int arr[], int left, int right) {
  if (left < right) {
    // Find the middle point
    int mid = left + (right - left) / 2;

    // Sort first and second halves
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
  }
}

// Function to print an array
void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Driver code
// see if we can find a + b = 14
int main() {
  int X = 14;
  int A[] = {12, 11, 13, 5, 6, 7};
  int B[] = {4, 2, 1, 8, 26, 17};
  int sizeA = sizeof(A) / sizeof(A[0]);
  int sizeB = sizeof(B) / sizeof(B[0]);

  merge_sort(A, 0, sizeA - 1);
  merge_sort(B, 0, sizeB - 1);

  int* aPtr = A;
  int* bPtr = B + sizeB - 1;

  while (aPtr < A + sizeA && bPtr >= B) {
    int sum = *aPtr + *bPtr;
    printf("Checking pair (%d, %d): sum = %d\n", *aPtr, *bPtr, sum);

    if (sum == X) {
      printf("Found pair: (%d, %d)\n", *aPtr, *bPtr);
      aPtr++;  // Move aPtr to next element in A[]
      bPtr--;  // Move bPtr to previous element in B[]
    } else if (sum < X) {
      aPtr++;  // Move aPtr to next element in A[]
    } else {
      bPtr--;  // Move bPtr to previous element in B[]
    }
  }
  return 0;
}
