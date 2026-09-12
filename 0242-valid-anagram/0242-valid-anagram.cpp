class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> st;
        for (char c : s) {
            st[c]++;
        }
        for (char c : t) {
            st[c]--;
        }
        for (char c : s) {
            if (st[c])
                return false;
        }
        return true;
    }
};