class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> cnt;
        set<int> cache;

        for(auto a:arr)
        {
            cnt[a]++;
        }

        for(auto c:cnt)
        {
            if(cache.count(c.second))
            {
                return false;
            }
            else
            {
                cache.insert(c.second);
            }
        }

        return true;
    }
};