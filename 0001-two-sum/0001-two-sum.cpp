class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> st;
        
        for(int i =0;i<nums.size();i++){
            int need = target - nums[i];
            if(st.find(need) != st.end()){
                return {st[need],i};
            }
            st[nums[i]] = i;
        }
        return {};
    }
};