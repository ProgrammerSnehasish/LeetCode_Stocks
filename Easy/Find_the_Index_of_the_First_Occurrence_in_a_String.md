#  Find the Index of the First Occurrence in a String (Easy)
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

- `1` <= haystack.length, needle.length <= `10^4`
- haystack and needle consist of only lowercase English characters.

---

## Solution in C
```c
#include <string.h>

int strStr(char* haystack, char* needle) {
    int h = strlen(haystack);
    int n = strlen(needle);

    if (n == 0) return 0;

    for (int i = 0; i <= h - n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == n)
            return i;
    }
    return -1;
}
```