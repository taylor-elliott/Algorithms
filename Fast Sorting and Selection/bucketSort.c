#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10  // Number of buckets
#define MAX_STRING_SIZE 50
// Tuple structure (key-value pair)
typedef struct Tuple {
  int key;
  char data[MAX_STRING_SIZE];
} Tuple;

// Node structure for linked list (to maintain order)
typedef struct Node {
  Tuple value;
  struct Node* next;
} Node;

// Function to insert a tuple at the end of a linked list (maintains stability)
void insert_end(Node** bucket, Tuple value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
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

// Function to perform stable Bucket Sort for tuples
void bucket_sort(Tuple arr[], int n) {
  Node* buckets[BUCKET_SIZE] = {NULL};

  // Find the min and max key values
  int min_key = arr[0].key, max_key = arr[0].key;
  for (int i = 1; i < n; i++) {
    if (arr[i].key < min_key)
      min_key = arr[i].key;
    if (arr[i].key > max_key)
      max_key = arr[i].key;
  }

  int range = max_key - min_key + 1;  // Adjust range to fit all values

  // Place elements into appropriate buckets based on key
  for (int i = 0; i < n; i++) {
    int bucket_index =
        ((arr[i].key - min_key) * BUCKET_SIZE) / range;  // Normalize index
    insert_end(&buckets[bucket_index], arr[i]);  // Append to maintain order
  }

  // Collect elements from buckets back into the array
  int index = 0;
  for (int i = 0; i < BUCKET_SIZE; i++) {
    Node* current = buckets[i];
    while (current != NULL) {
      arr[index++] = current->value;
      Node* temp = current;
      current = current->next;
      free(temp);  // Free memory
    }
  }
}

// Helper function to print an array of tuples
void print_array(Tuple arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("(%d, %s) ", arr[i].key, arr[i].data);
  }
  printf("\n");
}

// driver code
int main() {
  Tuple arr[] = {{29, "apple"}, {9, "fig1"},      {-25, "banana"},
                 {3, "cherry"}, {-49, "date"},    {-9, "elderberry"},
                 {9, "fig2"},   {9, "fig3"},      {9, "fig4"},
                 {37, "grape"}, {21, "honeydew"}, {-43, "kiwi"},
                 {9, "fig5"},   {29, "lime"}};

  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  print_array(arr, n);

  bucket_sort(arr, n);

  printf("Sorted array:\n");
  print_array(arr, n);

  return 0;
}
