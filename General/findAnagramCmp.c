#include "common.h"

/*
Let α = a1 a2 ... an and β = b1 b2 ... bn be two strings with symbols taken
from the English alphabet (only lowercase). We say that α and β are anagrams if
α can be formed from β by rearranging the letters of β. For example, the English
words silent and listen are anagrams.

Describe an algorithm to determine whether α and β are anagrams in O(n log n)
time.

Can you design an algorithm that is faster than O(n log n)? Note: You may assume
that the English alphabet is totally ordered, i.e., a < b < · · · < z
*/

int compareStrings(const void* a, const void* b) {
  return *(char*)a - *(char*)b;
}

int isAnagramCmp(char str1[], char str2[]) {
  if (strlen(str1) != strlen(str2))
    return 0;

  qsort(str1, strlen(str1), sizeof(char), compareStrings);
  qsort(str2, strlen(str2), sizeof(char), compareStrings);

  return strcmp(str1, str2) == 0;
}

/* int main(void) {
  char A[] = "silent";
  char B[] = "listen";
  char C[] = "silentx";
  char D[] = "listen";

  printf("A,B\n");
  if (isAnagram(A, B))
    printf("The strings are anagrams.\n");
  else
    printf("The strings are not anagrams.\n");

  printf("C,D\n");
  if (isAnagram(C, D))
    printf("The strings are anagrams.\n");
  else
    printf("The strings are not anagrams.\n");

  return 0;
} */