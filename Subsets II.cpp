class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& arr, int idx) {
        ans.push_back(arr);

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;

            arr.push_back(nums[i]);
            solve(nums, ans, arr, i + 1);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());

        solve(nums, ans, arr, 0);
        return ans;
    }
};
