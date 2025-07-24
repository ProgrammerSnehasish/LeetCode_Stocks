# Problem: Merge K Sorted List(Hard)
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

**Example 1:**

**Input:**  
`lists = [[1,4,5],[1,3,4],[2,6]]`  
**Output:**  
`[1,1,2,3,4,4,5,6]`  
**Explanation:**  
The linked-lists are:  
[
1->4->5,
1->3->4,
2->6
]

Merging them into one sorted linked list:  
`1->1->2->3->4->4->5->6`

**Example 2:**

**Input:**  
`lists = []`  
**Output:**  
`[]`

**Example 3:**

**Input:**  
`lists = [[]]`  
**Output:**  
`[]`

**Constraints:**

- `k == lists.length`  
- `0 <= k <= 10^4`  
- `0 <= lists[i].length <= 500`  
- `-10^4 <= lists[i][j] <= 10^4`  
- `lists[i]` is sorted in **ascending order**  
- The total number of nodes in all lists will not exceed `10^4`

# Solution(in C)
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    if (listsSize == 1) return lists[0];

    while (listsSize > 1) {
        int k = (listsSize + 1) / 2;  // Half the number of lists
        for (int i = 0; i < listsSize / 2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[i + k]);
        }
        listsSize = k;
    }
    return lists[0];
}
```