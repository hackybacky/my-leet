import queue
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        q = queue.Queue()
        n = len(mat)
        m = len(mat[0])
        ans =  [[10**17 for j in range(m)] for i in range(n)]
        print(ans)
        for i in range(n):
            for j in range(m):
                if mat[i][j] != 1:
                    q.put([i , j , 0])
                    ans[i][j] = 0
                    print(i , j , ans[i][j])
            
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        while q.empty() == False:
            cur = q.get()
            x = cur[0]
            y = cur[1]
            d = cur[2]
            for j in range(4):
                nx = x + directions[j][0]
                ny = y + directions[j][1]
                # print(nx , ny , ans[nx][ny])
                if nx < 0 or nx >= n or ny < 0 or ny >= m or ans[nx][ny] <= d + 1:
                    continue
                # print("f")
                ans[nx][ny] = d +1
                # print(nx , ny)
                q.put([nx , ny , d + 1])
            
        return ans