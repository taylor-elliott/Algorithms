void findMinMax(float arr[], int n, float* min, float* max) {
  *min = arr[0];
  *max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < *min)
      *min = arr[i];
    if (arr[i] > *max)
      *max = arr[i];
  }
}
