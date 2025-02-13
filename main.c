#include <stdio.h>
#include "common.h"
#include "general.h"

#define NUM_TESTS 11

int main(void) {
  int passCount = 0;
  int totalTests = NUM_TESTS;
  int result;

  // Test 1: Standard anagram case
  result = isAnagramFrequency("silent", "listen");
  if (result) {
    printf(GREEN "Test 1 passed: 'silent' and 'listen' are anagrams.\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 1 failed: 'silent' and 'listen' should be anagrams.\n" RESET);
  }

  // Test 2: Different lengths (should not be anagrams)
  result = !isAnagramFrequency("silent", "listens");
  if (result) {
    printf(GREEN
           "Test 2 passed: Strings of different lengths are not "
           "anagrams.\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 2 failed: Strings of different lengths cannot be "
           "anagrams.\n" RESET);
  }

  // Test 3: Anagram with different ordering
  result = isAnagramFrequency("evil", "vile");
  if (result) {
    printf(GREEN "Test 3 passed: 'evil' and 'vile' are anagrams.\n" RESET);
    passCount++;
  } else {
    printf(RED "Test 3 failed: 'evil' and 'vile' should be anagrams.\n" RESET);
  }

  // Test 4: Identical strings are trivially anagrams
  result = isAnagramFrequency("abc", "abc");
  if (result) {
    printf(GREEN "Test 4 passed: Identical strings are anagrams.\n" RESET);
    passCount++;
  } else {
    printf(RED "Test 4 failed: Identical strings should be anagrams.\n" RESET);
  }

  // Test 5: Spaces with Anagram
  result = !isAnagramFrequency("a b c", "c b a");
  if (result) {
    printf(GREEN
           "Test 5 passed: 'a b c' and 'c b a' are not considered "
           "anagrams.\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 5 failed: 'a b c' and 'c b a' should be considered "
           "anagrams.\n" RESET);
  }

  // Test 6: One string is empty while the other is not (should not be anagrams)
  result = !isAnagramFrequency("abc", "");
  if (result) {
    printf(GREEN
           "Test 6 passed: one empty and one non-empty string are not "
           "anagrams.\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 6 failed: one empty and one non-empty string should not be "
           "anagrams.\n" RESET);
  }

  // Test 7: Invalid input: uppercase letter in one string (should be invalid)
  result = !isAnagramFrequency("abc", "Abc");
  if (result) {
    printf(GREEN
           "Test 7 passed: 'abc' and 'Abc' are not considered anagrams "
           "(invalid input).\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 7 failed: 'abc' and 'Abc' should not be anagrams due to "
           "invalid input.\n" RESET);
  }

  // Test 8: Invalid input: special characters in strings (should be invalid)
  result = !isAnagramFrequency("a#c", "c#a");
  if (result) {
    printf(GREEN
           "Test 8 passed: 'a#c' and 'c#a' are not considered anagrams "
           "(invalid input).\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 8 failed: 'a#c' and 'c#a' should not be anagrams due to "
           "invalid input.\n" RESET);
  }

  // Test 9: Invalid input: empty strings(should be invalid)
  result = !isAnagramFrequency("", "c#a");
  if (result) {
    printf(GREEN
           "Test 8 passed: '' and 'c#a' are not considered anagrams "
           "(invalid input).\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 8 failed: '' and 'c#a' should not be anagrams due to "
           "invalid input.\n" RESET);
  }

  // Test 10: Invalid input: empty strings(should be invalid)
  result = !isAnagramFrequency("c#a", "");
  if (result) {
    printf(GREEN
           "Test 10 passed: 'c#a' and '' are not considered anagrams "
           "(invalid input).\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 10 failed: 'c#a' and '' should not be anagrams due to "
           "invalid input.\n" RESET);
  }

  // Test 11: Invalid input: empty strings (should be invalid)
  result = !isAnagramFrequency("", "");
  if (result) {
    printf(GREEN
           "Test 11 passed: '' and '' are not considered anagrams "
           "(invalid input).\n" RESET);
    passCount++;
  } else {
    printf(RED
           "Test 11 failed: '' and '' should not be anagrams due to "
           "invalid input.\n" RESET);
  }

  // Summary of test results
  if (passCount == totalTests) {
    printf(GREEN "\nAll tests passed!\n" RESET);
  } else {
    printf(RED "\n%d/%d tests passed.\n" RESET, passCount, totalTests);
  }

  return 0;
}