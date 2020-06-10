class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> vmap;
        for(int i = 0; i < nums.size(); i++)
        {
            if(vmap.find(target - nums[i]) != vmap.end())
            {
                return {i,vmap[target-nums[i]]};
            }

            vmap[nums[i]] = i;
        }

        return {};
    }
};