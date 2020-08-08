class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int nSum = 0;
        int nMinScore = 2147483647;
        int nTemp = 0;
        int nLength = cardPoints.size() - k;
        for(int i = 0; i < cardPoints.size(); i++)
        {
            nSum = nSum + cardPoints[i];
        }

        if(k == cardPoints.size())
        {
            return nSum;
        }

        for(int i = 0; i < cardPoints.size(); i++)
        {
            nTemp = nTemp + cardPoints[i];
            if(i >= nLength)
            {
                nTemp = nTemp - cardPoints[i - nLength];
            }

            if(i >= nLength - 1)
            {
                if(nMinScore > nTemp)
                {
                    nMinScore = nTemp;
                }
            }
        }

        return nSum - nMinScore;
    }
};