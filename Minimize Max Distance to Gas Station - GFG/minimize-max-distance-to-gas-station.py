#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends
#User function Template for python3

class Solution:
    def findSmallestMaxDist(self, stations, K):
        # Code here
        n = len(stations)
        low = 0
        high = 10 ** 6
        ans = 0
        while (high - low) > 10 ** (-5):
            mid = (high + low)/ 2.0
            cur = 0
            for i in range(1 , n):
                curd = stations[i] - stations[i - 1]
                if curd > mid:
                    req = math.ceil(curd / mid)
                    cur += (req - 1)
            if cur <= K:
                high = mid
                ans = mid
            else :
                low = mid
        return ans
                    

#{ 
 # Driver Code Starts.
import math
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        stations = list(map(int, input().split()))
        K = int(input())
        ob = Solution()
        print('%.2f' % ob.findSmallestMaxDist(stations, K))
# } Driver Code Ends