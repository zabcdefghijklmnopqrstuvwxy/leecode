class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while(len(stones)>=2):
            stones.sort()
            stones.append(stones.pop()-stones.pop())

        return stones[0]

