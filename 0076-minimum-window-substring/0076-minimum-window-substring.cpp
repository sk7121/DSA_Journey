
class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> required;
        unordered_map<char, int> window;

        for (char c : t) {
            required[c]++;
        }

        int left = 0;
        int have = 0;
        int required_size = required.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];

            window[c]++;
            if (required.count(c) && window[c] == required[c]) {
                have++;
            }
            while (have == required_size) {
                int windowLen = right - left + 1;

                if (windowLen < minLen) {
                    minLen = windowLen;
                    start = left;
                }
                char leftChar = s[left];

                window[leftChar]--;
                if (required.count(leftChar) &&
                    window[leftChar] < required[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};