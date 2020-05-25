"""
Construct Binary Search Tree from Preorder Traversal
Solution
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.

"""

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def insert(self, cur_node, num):
        if num < cur_node.val:
            if cur_node.left:
                cur_node = cur_node.left
                self.insert(cur_node, num)
            else:
                cur_node.left = TreeNode(num)
        else:
            if cur_node.right:
                cur_node = cur_node.right
                self.insert(cur_node, num)
            else:
                cur_node.right = TreeNode(num)
        return

    def bstFromPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: TreeNode
        """
        root = TreeNode(preorder[0])
        for num in preorder[1:]:
            cur_node = root
            self.insert(cur_node, num)
        return root
