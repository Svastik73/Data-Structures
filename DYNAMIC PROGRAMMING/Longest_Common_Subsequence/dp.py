class Solution(object):
    def revers(self,s):
        t=""
        for i in range(len(s)-1,-1,-1):
            t+=s[i]
        return t
        

    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        t=self.revers(s)
        n=len(s)
        dp=[]
        for i in range(n+1):
            ld=[]
            for j in range(n+1):
                ld.append(0)
            dp.append(ld)
        for i in range(1,n+1):
            for j in range(1,n+1):
                if s[i-1]==t[j-1]:
                    dp[i][j]=1+dp[i-1][j-1]
                else:
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])
        return dp[n][n]
