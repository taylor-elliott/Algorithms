#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 4
int seen_count = 0;
int seen[24][N] = {0};  // Store unique permutations

// Function to swap two adjacent elements
void swap_adjacent(int arr[], int i) {
  int temp = arr[i];
  arr[i] = arr[i + 1];
  arr[i + 1] = temp;
}

// Function to print an array
void print_array(int arr[], int n, int step) {
  printf("%d ", step);
  for (int j = 0; j < n; j++) {
    printf("%d", arr[j]);
  }
  printf("\n");
}

// Function to check if a permutation was already generated
bool is_duplicate(int arr[]) {
  for (int i = 0; i < seen_count; i++) {
    if (memcmp(seen[i], arr, N * sizeof(int)) == 0) {
      return true;
    }
  }
  return false;
}

// Function to generate permutations using max adjacent transpositions
void max_adjacent_transpositions(int arr[], int n) {
  memcpy(seen[seen_count], arr, N * sizeof(int));
  print_array(arr, n, ++seen_count);

  for (int value = n; value > 1; value--) {  // Move largest value left first
    int pos = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == value) {
        pos = i;
        break;
      }
    }

    while (pos > 0) {  // Shift the value left step by step
      swap_adjacent(arr, pos - 1);
      pos--;

      if (!is_duplicate(arr)) {
        memcpy(seen[seen_count], arr, N * sizeof(int));
        print_array(arr, n, ++seen_count);
      }
    }
  }

  // Generate the remaining permutations
  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 2; j >= 0; j--) {  // Swap adjacent pairs in reverse order
      swap_adjacent(arr, j);
      if (!is_duplicate(arr)) {
        memcpy(seen[seen_count], arr, N * sizeof(int));
        print_array(arr, n, ++seen_count);
      }
    }
  }
}

int main() {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("All 24 permutations using maximum adjacent transpositions:\n");
  max_adjacent_transpositions(arr, n);

  return 0;
}
