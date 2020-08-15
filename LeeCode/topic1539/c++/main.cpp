class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] - i - 1 >= k)
            {
                return i + k;
            }
        }

        return arr.size() + k;
    }
};