# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def generate(self , start , end ):
        if(start > end) :
            return [None]
        ans = []
        for i in range(start , end + 1):
            left = self.generate(start , i - 1)
            right = self.generate(i + 1 , end)
            
            for j in left :
                for k in right :
                    node = TreeNode(i)
                    node.left = j
                    node.right = k
                    ans.append(node)
        return ans
        
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        self.visited = [0]*(n + 1)
        self.visited[1] = 1
        return self.generate(1 , n)