class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        repeatDict = {}
        for num in nums:
            if num not in repeatDict:
                repeatDict[num] = 1
            else:
                return num