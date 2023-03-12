# 226. Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

Example 1:
![](https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg)

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
![](https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg)

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

# Solution

Method 1:

1. Add root node to the queue
2. Traverse through the tree using the queue
3. Swap left and right of each node
4. Add the left and right to the end of the queue

Runtime 4 ms Beats 33.53%
Memory 9.7 MB Beats 46.42%

Method 2:
Recursive algorithm

1. If root node is null return null
2. Swap left and right
3. call invertTree on the left node
4. call invertTree on the right node

Runtime 3 ms Beats 60.47%
Memory 9.7 MB Beats 86.5%
