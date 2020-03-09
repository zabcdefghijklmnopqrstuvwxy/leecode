class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set()
        ret = 0
        for n in nums:
            s.add(n)
        for n in nums:
            if n-1 not in s:
                tmp = 1
                while n+1 in s:
                    n += 1
                    tmp += 1
                ret = max(ret, tmp)
        return ret