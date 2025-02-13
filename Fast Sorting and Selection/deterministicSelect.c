#include <limits.h>
#include <math.h>
#include <stdio.h>

//==================================================================
void findBabyMedians(float S[], int n, float babyMedians[], int g) {
  int i, j, k;
  for (i = 1; i + 5 <= n; i += 5) {
    int bIndex = (i + 4) / 5;
    for (j = 0; j < 3; ++j) {
      int index = j;
      for (k = index; k < 5; ++k)
        if (S[i + k] <= S[i + index])
          index = k;
      float temp = S[i + index];
      S[i + index] = S[i + j];
      S[i + j] = temp;
    }
    babyMedians[bIndex] = S[i + 2];
  }
  if (n - i + 1 > 0) {
    for (j = 0; j < n - i + 1; ++j) {
      int index = j;
      for (k = index; k < n - i + 1; ++k)
        if (S[i + k] <= S[i + index])
          index = k;
      float temp = S[i + index];
      S[i + index] = S[i + j];
      S[i + j] = temp;
    }
    babyMedians[g] = S[i + (n - i + 1) / 2];
  }
}
//==================================================================
float DeterministicSelect(float S[], int n, int k) {
  if (n == 1)
    return S[1];

  int i;
  int g = (n + 4) / 5;
  float babyMedians[g + 1];

  findBabyMedians(S, n, babyMedians, g);

  float x = DeterministicSelect(babyMedians, g, (g + 1) / 2);

  float L[n + 1], E[n + 1], G[n + 1];
  int lengthL = 0, lengthE = 0, lengthG = 0;

  for (i = 1; i <= n; ++i) {
    if (S[i] < x)
      L[++lengthL] = S[i];
    else if (S[i] > x)
      G[++lengthG] = S[i];
    else
      E[++lengthE] = S[i];
  }

  if (k <= lengthL)
    return DeterministicSelect(L, lengthL, k);
  else if (k <= lengthL + lengthE)
    return x;
  else
    return DeterministicSelect(G, lengthG, k - lengthL - lengthE);
}