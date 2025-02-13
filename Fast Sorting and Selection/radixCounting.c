#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_RANGE 256

/*
   Suitable:

    ✔ When keys are short (bounded k)
    ✔ When sorting large datasets
    ✔ When stability is required

 */

// finding Maximum Key Length → O(n)
int get_max_length(char arr[][50], int n) {
  int max_len = strlen(arr[0]);
  for (int i = 1; i < n; i++) {
    int len = strlen(arr[i]);
    if (len > max_len)
      max_len = len;
  }
  return max_len;
}

// stable counting sort for a specific character position
void counting_sort(char arr[][50], int n, int pos, int max_len) {
  char output[n][50];
  int count[ASCII_RANGE] = {0};  // frequency array

  // count occurrences of each character (or empty space for shorter words)
  for (int i = 0; i < n; i++) {
    char ch = (pos < strlen(arr[i])) ? arr[i][pos] : 0;  // 0 for shorter words
    count[(int)ch]++;
  }

  // convert counts to cumulative positions
  for (int i = 1; i < ASCII_RANGE; i++) {
    count[i] += count[i - 1];
  }

  // build the output array (stable sorting)
  for (int i = n - 1; i >= 0; i--) {
    char ch = (pos < strlen(arr[i])) ? arr[i][pos] : 0;
    strcpy(output[count[(int)ch] - 1], arr[i]);
    count[(int)ch]--;
  }

  // copy sorted output back to original array
  for (int i = 0; i < n; i++) {
    strcpy(arr[i], output[i]);
  }
}

// radix Sort for lexicographic sorting
void radix_sort(char arr[][50], int n) {
  int max_len = get_max_length(arr, n);

  // sort from rightmost character to leftmost (LSB to MSB)
  for (int pos = max_len - 1; pos >= 0; pos--) {
    counting_sort(arr, n, pos, max_len);
  }
}

void print_array(char arr[][50], int n) {
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }
}

// driver code
int main() {
  char arr[][50] = {"aab", "bba", "abb", "bab", "bbb",
                    "aab", "aba", "aaa", "baa", "aaa"};

  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  print_array(arr, n);

  radix_sort(arr, n);

  printf("\nSorted array:\n");
  print_array(arr, n);

  return 0;
}
