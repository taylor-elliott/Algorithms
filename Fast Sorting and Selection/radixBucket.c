#include <stdio.h>
#include <stdlib.h>

#define BASE 10

/*

✅ Time Complexity: O(n * d) (linear for small d)
✅ Stable: Yes
✅ Preserves Lexicographic Order
✅ Efficient for Large Tuples 🚀

*/

typedef struct Tuple {
  int first;
  int second;
} Tuple;

typedef struct Node {
  Tuple data;
  struct Node* next;
} Node;

int get_max(Tuple arr[], int n, int position) {
  int max_val = (position == 0) ? arr[0].first : arr[0].second;
  for (int i = 1; i < n; i++) {
    int value = (position == 0) ? arr[i].first : arr[i].second;
    if (value > max_val)
      max_val = value;
  }
  return max_val;
}

void insert_bucket(Node** bucket, Tuple data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*bucket == NULL) {
    *bucket = newNode;
  } else {
    Node* current = *bucket;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

void bucket_sort(Tuple arr[], int n, int place, int position) {
  Node* buckets[BASE] = {NULL};

  for (int i = 0; i < n; i++) {
    int num = (position == 0) ? arr[i].first : arr[i].second;
    int digit = (num / place) % BASE;
    insert_bucket(&buckets[digit], arr[i]);
  }

  int index = 0;
  for (int i = 0; i < BASE; i++) {
    Node* current = buckets[i];
    while (current != NULL) {
      arr[index++] = current->data;
      Node* temp = current;
      current = current->next;
      free(temp);
    }
  }
}

// sorting first by second, then by first
void radix_sort(Tuple arr[], int n) {
  // sort by second element first
  int max_second = get_max(arr, n, 1);
  for (int place = 1; max_second / place > 0; place *= BASE) {
    bucket_sort(arr, n, place, 1);
  }

  // sort by first element (ensuring lexicographic order)
  int max_first = get_max(arr, n, 0);
  for (int place = 1; max_first / place > 0; place *= BASE) {
    bucket_sort(arr, n, place, 0);
  }
}

void print_array(Tuple arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("(%d, %d)\n", arr[i].first, arr[i].second);
  }
}

// driver code
int main() {
  Tuple arr[] = {{3, 3}, {1, 5}, {2, 5}, {1, 2},
                 {2, 3}, {1, 7}, {3, 2}, {2, 2}};

  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  print_array(arr, n);

  radix_sort(arr, n);

  printf("\nSorted array:\n");
  print_array(arr, n);

  return 0;
}
