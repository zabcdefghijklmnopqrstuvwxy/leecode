class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        cnt=0
        people.sort()
        left, right = 0, len(people) - 1

        while(left<=right):
            if people[right] == limit:
                cnt+=1
                right-=1
            elif people[left] + people[right] <= limit:
                cnt+=1
                right-=1
                left+=1
            else:
                cnt+=1
                right-=1 
        
        return cnt