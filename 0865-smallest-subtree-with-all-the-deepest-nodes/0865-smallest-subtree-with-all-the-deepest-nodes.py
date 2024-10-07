# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        @cache
        def depth(root):
            if root == None:
                return 0
            return max(depth(root.left), depth(root.right)) + 1
        
        L = depth(root.left)
        R = depth(root.right)
        if L == R:
            return root
        elif L > R:
            return self.subtreeWithAllDeepest(root.left)
        else:
            return self.subtreeWithAllDeepest(root.right)