# Problem: Merge Sorted Array(Easy)

You are given two integer arrays `nums1` and `nums2`, sorted in non-decreasing order, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should **not be returned** by the function, but instead be **stored inside the array `nums1`**. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

**Example 1**

**Input:**  
`nums1 = [1,2,3,0,0,0], m = 3`  
`nums2 = [2,5,6], n = 3`

**Output:**  
`[1,2,2,3,5,6]`


**Example 2**

**Input:**  
`nums1 = [1], m = 1`  
`nums2 = [], n = 0`

**Output:**  
`[1]`


**Example 3**

**Input:**  
`nums1 = [0], m = 0`  
`nums2 = [1], n = 1`

**Output:**  
`[1]`


**Constraints**
- `nums1.length == m + n`
- `nums2.length == n`
- `0 <= m, n <= 200`
- `1 <= m + n <= 200`
- `-10⁹ <= nums1[i], nums2[j] <= 10⁹`

# Solution(in C)
```c
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;            // Pointer to last valid element in nums1
    int j = n - 1;            // Pointer to last element in nums2
    int k = m + n - 1;        // Pointer to last position in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
```