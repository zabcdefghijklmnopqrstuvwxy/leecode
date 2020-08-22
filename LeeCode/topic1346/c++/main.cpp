class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> gather;
        for(int i = 0; i < arr.size(); i++)
        {
            if(gather.find(2*arr[i]) != gather.end() || (gather.find(arr[i]/2) != gather.end() && arr[i] % 2 == 0))
            {
                return true;
            }
            else
            {
                gather.insert(arr[i]);
            }
        } 

        return false;
    }
};