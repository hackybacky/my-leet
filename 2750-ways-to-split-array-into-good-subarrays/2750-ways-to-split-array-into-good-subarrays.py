class Solution(object):
    def numberOfGoodSubarraySplits(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = dict()
        n = len(nums)
        mod = 1000000007
        def recur(index , take) :
            if index == n:
                return 1 if take == 1 else 0
            if (index ,take) in dp :
                return dp[(index , take)]
            cur = nums[index] == 1
            if cur :
                ans = recur(index + 1 , 1)
            else:
                if take > 0:
                    ans = (recur(index + 1 , take) + recur(index + 1 , 0) )%mod
                else :
                    ans = recur(index + 1 , take)
            dp[(index , take)] = ans % mod
            return dp[(index , take)]
        ans = recur(0 , -1)
        return ans
                    
                
        
        