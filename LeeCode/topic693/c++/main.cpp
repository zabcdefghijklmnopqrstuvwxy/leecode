class Solution {
public:
    bool hasAlternatingBits(int n) {
        long nTmp = n ^ (n >> 1);
        return (nTmp & (nTmp + 1)) == 0;
    }
};