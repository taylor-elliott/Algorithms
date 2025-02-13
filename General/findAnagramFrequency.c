#include <string.h>
#include "common.h"
#include "general.h"

#define ALPHABET_SIZE 26

int isAnagramFrequency(const char* str1, const char* str2) {
  // Treat empty strings as invalid input.
  if (strlen(str1) == 0 || strlen(str2) == 0)
    return 0;

  // If lengths differ, they can't be anagrams.
  if (strlen(str1) != strlen(str2))
    return 0;

  int freq[ALPHABET_SIZE] = {0};

  // Process the first string.
  for (int i = 0; str1[i] != '\0'; i++) {
    char c = str1[i];
    // Validate that the character is a lowercase letter.
    if (c < 'a' || c > 'z')
      return 0;
    freq[c - 'a']++;
  }

  // Process the second string.
  for (int i = 0; str2[i] != '\0'; i++) {
    char c = str2[i];
    // Validate that the character is a lowercase letter.
    if (c < 'a' || c > 'z')
      return 0;
    freq[c - 'a']--;
  }

  // Check that all counts are zero.
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (freq[i] != 0)
      return 0;
  }

  return 1;
}
