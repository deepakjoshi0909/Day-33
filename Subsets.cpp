class Solution {
public:
    void solve(vector<int>& nums, vector<int>& arr, vector<vector<int>>& ans, int idx) {
        ans.push_back(arr);

        for (int i = idx; i < nums.size(); i++) {
            arr.push_back(nums[i]);
            solve(nums, arr, ans, i + 1); 
            arr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(nums, arr, ans, 0);
        return ans;
    }
};
