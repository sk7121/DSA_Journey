class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int min_value = *min_element(nums.begin(),nums.end());
        int max_value = *max_element(nums.begin(),nums.end());
        unordered_set<int> st(nums.begin(),nums.end());

        vector<int> result;
        for(int i = min_value;i<=max_value;i++){
            if(!st.count(i)){
                result.push_back(i);
            }
        }
        return result;
    }
};