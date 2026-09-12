int rob_part(int begin, int end, vector<int>& nums) {
    int len = end - begin;
    if (len == 0)
        return 0;
    if (len == 1)
        return nums[begin];

    int prev2 = nums[begin];
    int prev1 = max(nums[begin], nums[begin + 1]);

    for (int i = begin + 2; i < end; i++) {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(rob_part(0, nums.size() - 1, nums),
                   rob_part(1, nums.size(), nums));
    }
};