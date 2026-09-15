class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> st;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (st.find(key) != st.end()) {
                int idx = st[key];
                result[idx].push_back(strs[i]);
            } else {
                int idx = result.size();
                st[key] = idx;
                result.push_back({strs[i]});
            }
        }
        return result;
    }
};