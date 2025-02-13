#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define N 4

// Function to perform prefix reversal
void reverse_prefix(int arr[], int k) {
  for (int i = 0, j = k - 1; i < j; i++, j--) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

// Function to print an array
void print_array(int arr[], int n, int step) {
  printf("%d ", step);
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  printf("\n");
}

// Function to check if a permutation was already generated
bool is_duplicate(int seen[24][N], int arr[], int count) {
  for (int i = 0; i < count; i++) {
    if (memcmp(seen[i], arr, N * sizeof(int)) == 0) {
      return true;
    }
  }
  return false;
}

// Function to generate all permutations using minimum prefix reversals
void generate_permutations(int arr[], int n, int seen[24][N], int* count) {
  if (*count == 24) {
    return;
  }

  if (!is_duplicate(seen, arr, *count)) {
    memcpy(seen[*count], arr, N * sizeof(int));
    print_array(arr, n, *count + 1);
    (*count)++;
  }

  for (int k = 2; k <= n; k++) {
    reverse_prefix(arr, k);
    if (!is_duplicate(seen, arr, *count)) {
      generate_permutations(arr, n, seen, count);
    }
    reverse_prefix(arr, k);  // Backtrack to original state
  }
}

int main() {
  int arr[] = {1, 2, 3, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  int seen[24][N] = {0};  // Store unique permutations
  int count = 0;

  printf("All 24 permutations using minimum prefix reversals:\n");
  generate_permutations(arr, n, seen, &count);

  return 0;
}
