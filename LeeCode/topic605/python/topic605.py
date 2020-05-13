class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        tmp = [0] + flowerbed + [0]
        for i in range(1,len(tmp) - 1):
            if tmp[i-1] == 0 and tmp[i] == 0 and tmp[i+1] == 0 :
                tmp[i]=1
                n-=1

        return n<=0