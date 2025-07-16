# Problem: Power of Three(Easy)
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

**Example 1:**

**Input:** n = 27
**Output:** true
**Explanation:** 27 = 3³

**Example 2:**

**Input:** n = 0
**Output:** false
**Explanation:** There is no x where 3^x = 0.

**Example 3:**

**Input:** n = -1
**Output:** false
**Explanation:** There is no x where 3x = (-1).
 
**Constraints:**
- **-2³¹ <= x <= 2³¹ - 1**

# Solution(in C)
```c
bool isPowerOfThree(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}
```