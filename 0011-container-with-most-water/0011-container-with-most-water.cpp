class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_value = 0;

        int i = 0;
        int j = height.size() - 1;

        while (i < j) {

            int area = min(height[i], height[j]) * (j - i);

            max_value = max(max_value, area);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return max_value;
    }
};