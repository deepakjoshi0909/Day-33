class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& candidates, int target, int sum, int idx) {
        if (sum == target) {
            ans.push_back(arr);
            return;
        } else if (sum > target) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            
            arr.push_back(candidates[i]);
            solve(arr, ans, candidates, target, sum + candidates[i], i + 1); 
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> arr;
        vector<vector<int>> ans;
        
        solve(arr, ans, candidates, target, 0, 0);
        return ans;
    }
};
