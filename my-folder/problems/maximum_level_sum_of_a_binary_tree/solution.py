# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

import queue

class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        q= queue.Queue()

        q.put(root)
        
        level=1
        ans=1
        max=root.val
        while not q.empty():
            temp=q.qsize()
            sum=0
            for i in range (temp):
                node=q.get()
                sum +=node.val
                if(node.left):
                    q.put(node.left)
                if(node.right):
                    q.put(node.right)
            if(sum>max):
                max=sum
                ans=level
            level+=1
        
        return ans
