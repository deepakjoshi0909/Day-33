class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for (int i = idx; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) {
                continue;
            }
            used.insert(nums[i]);
            swap(nums[idx], nums[i]);
            solve(nums, ans, idx + 1);
            swap(nums[idx], nums[i]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, ans, 0);
        return ans;
    }
};
