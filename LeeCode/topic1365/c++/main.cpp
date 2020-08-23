class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        int buf[101] = {0};
        memset(buf,0,sizeof(buf));
        int nCnt = 0;
        for(int num:nums)
        {
            buf[num]++;
        }

        for(int i = 0; i <= 100; i++)
        {
            if(buf[i])
            {
                int nTmp =  buf[i];
                buf[i] = nCnt;
                nCnt += nTmp;
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            ret.push_back(buf[nums[i]]);
        }

        return ret;
    }
};