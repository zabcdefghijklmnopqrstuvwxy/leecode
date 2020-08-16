class Solution {
public:
    double average(vector<int>& salary) {
        int nMin = INT_MAX;
        int nMax = INT_MIN;
        double nSum = 0;
        for(int i = 0; i < salary.size(); i++)
        {
            if(salary[i] > nMax)
            {
                nMax = salary[i];
            }

            if(salary[i] < nMin)
            {
                nMin = salary[i];
            }

            nSum = nSum + salary[i];
        }

        return (nSum - nMax - nMin)/(salary.size() - 2);
    }
};