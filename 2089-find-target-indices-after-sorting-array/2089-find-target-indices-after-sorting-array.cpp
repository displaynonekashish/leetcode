class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, same = 0;
        for (int x : nums) {
            if (x < target) less++;
            else if (x == target) same++;
        }
        vector<int> ans;
        for (int i = 0; i < same; i++) {
            ans.push_back(less + i);
        }
        return ans;
    }
};