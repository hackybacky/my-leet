class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 1:
            return 0
        if n == 2:
            return abs(nums[0] - nums[1])
        mx = max(nums)
        mn = min(nums)
        min_gap = (mx - mn + n - 2)/(n - 1)
        
        bmin = [10**18 ] * n
        bmax = [-10**18] * n
        
        for i in range(n):
            if nums[i] == mn or nums[i] == mx:
                continue
            index = (nums[i] - mn)/min_gap
            bmin[index] = min(bmin[index] , nums[i])
            bmax[index] = max(bmax[index] , nums[i])
        previous = mn
        print(bmax)
        max_gap = 0
        for i in range(0, n ):
            if bmin[i] == 10**18 and bmax[i] == -10**18:
                continue
            max_gap = max(max_gap , bmin[i] - previous)
            previous = bmax[i]
            
        max_gap = max(max_gap , mx - previous)
        return max_gap
        return mx
        