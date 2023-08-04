'''
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


[
[1,3,1]
[1,5,1]
[4,2,1]
]
answer=1+3+1+1+1==7

'''
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        m = len(grid[0])
        ls = []
        for i in range(len(grid)):
            l=[]
            for j in range(len(grid[i])):
                l.append(0)
            ls.append(l)
        ls[0][0] = grid[0][0]
        for i in range(n):
            for j in range(m):
                if i != 0 or j != 0:
                    r = 201 if i == 0 else ls[i-1][j]
                    c = 201 if j == 0 else ls[i][j-1]
                    ls[i][j] = grid[i][j] + min(r, c)
        return ls[n-1][m-1]
