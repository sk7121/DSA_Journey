class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            mp[s[right]]++;

            maxFreq = max(maxFreq, mp[s[right]]);

            int windowSize = right - left + 1;
            int replaceCount = windowSize - maxFreq;

            while (replaceCount > k) {
                mp[s[left]]--;
                left++;

                windowSize = right - left + 1;
                replaceCount = windowSize - maxFreq;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};