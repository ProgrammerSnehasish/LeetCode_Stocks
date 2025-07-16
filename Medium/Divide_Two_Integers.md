# Problem: Divide Two Integers(Medium)
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [-2³¹, 2³¹ − 1]. For this problem, if the quotient is strictly greater than 2³¹ - 1, then return 2³¹ - 1, and if the quotient is strictly less than -231, then return -2³¹.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

- **-2³¹ <= dividend, divisor <= 2³¹ - 1**
- **divisor != 0**
# Solution(in C)
```c
int divide(int dividend, int divisor) {
    // Handle overflow case: INT_MIN / -1 = 2^31, which is out of 32-bit int
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    // Determine sign of result
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Convert both to long to avoid overflow, and take absolute values
    long long ldividend = labs((long long)dividend);
    long long ldivisor = labs((long long)divisor);
    int quotient = 0;

    while (ldividend >= ldivisor) {
        long long temp = ldivisor, multiple = 1;
        // Double the divisor until it is less than or equal to dividend
        while (ldividend >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        quotient += multiple;
    }

    return sign * quotient;
}
```