class Solution {
public:
    int maxPower(string s) {
        if (s.length() == 0)
	        return 0;
        int ans = 1;
        int count = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else {
                count = 1;
            }
            ans = ans > count ? ans : count;
            //ans = Math.max(ans, count);
        }
        return ans;
    }
};