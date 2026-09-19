class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            if (mp.find(target - numbers[i]) != mp.end()) {
                result.push_back(mp[target - numbers[i]]);
                result.push_back(i + 1);
                return result;
            } else
                mp[numbers[i]] = i + 1;
        }
        return result;
    }
};