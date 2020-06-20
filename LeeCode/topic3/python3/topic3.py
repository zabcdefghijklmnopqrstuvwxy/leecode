
class Solution:
    def lengthOfLongestSubstring(self,s:str)-> int:
        st = {}
        i,ans = 0 , 0
        for j in range(len(str)):
            if s[j] in st:
                i = max(st[s[j]], i)
            ans = max(ans, j - i + 1)
            st[s[j]] = j + 1

        return ans






