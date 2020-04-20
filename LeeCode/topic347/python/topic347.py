class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c=collections.Counter(nums)
        t=c.most_common(k)
        return dict(t)