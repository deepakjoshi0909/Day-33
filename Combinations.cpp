class Solution {
public:
    void solve(int n,int k,vector<int>& arr, vector<vector<int>>& ans,int idx){
        if(arr.size() == k){
            ans.push_back(arr);
            return ;
        }

        for(int i=idx;i<=n;i++){
            arr.push_back(i);
            solve(n,k,arr,ans,i+1);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        vector<vector<int>>ans;

        solve(n,k,arr,ans,1);
        return ans;
    }
};
