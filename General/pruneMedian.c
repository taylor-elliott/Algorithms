#include <stdio.h>
#include <stdlib.h>

// Structure to hold elements with their weights
typedef struct {
  int value;
  double weight;
} Element;

// Function to compare two elements (for qsort)
int compare(const void* a, const void* b) {
  return ((Element*)a)->value - ((Element*)b)->value;
}

// Function to find the deterministic select (median of X)
Element deterministicSelect(Element* X, int n, int k) {
  qsort(X, n, sizeof(Element), compare);
  return X[k - 1];
}

// Function to find the weighted median
Element pruneMedian(Element* X, int n, double W) {
  printf("Recursive call with X = { ");
  for (int i = 0; i < n; i++) {
    printf("(%d, %.2f) ", X[i].value, X[i].weight);
  }
  printf("} and W = %.2f\n", W);

  if (n == 1) {
    return X[0];
  }

  // Select median
  Element y = deterministicSelect(X, n, (n + 1) / 2);

  // Compute weights
  double w1 = 0, w2 = 0;
  for (int i = 0; i < n; i++) {
    if (X[i].value < y.value) {
      w1 += X[i].weight;
    } else if (X[i].value <= y.value) {
      w2 += X[i].weight;
    }
  }

  if (w1 > W) {
    // y is too large, prune elements greater than y
    Element* X_prime = (Element*)malloc(n * sizeof(Element));
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (X[i].value < y.value) {
        X_prime[index++] = X[i];
      }
    }
    Element result = pruneMedian(X_prime, index, W);
    free(X_prime);
    return result;
  } else if (w1 + w2 < W) {
    // y is too small, prune elements less than y
    Element* X_prime = (Element*)malloc(n * sizeof(Element));
    int index = 0;
    for (int i = 0; i < n; i++) {
      if (X[i].value > y.value) {
        X_prime[index++] = X[i];
      }
    }
    Element result = pruneMedian(X_prime, index, W - (w1 + w2));
    free(X_prime);
    return result;
  } else {
    return y;
  }
}

int main() {
  Element X[] = {{21, 30},  {7, 20},   {19, 10}, {44, 12},
                 {50, 120}, {49, 180}, {3, 80},  {30, 14}};
  int n = sizeof(X) / sizeof(X[0]);
  double W = 466;

  Element median = pruneMedian(X, n, W / 2);
  printf("Weighted Median: %d\n", median.value);
  return 0;
}
