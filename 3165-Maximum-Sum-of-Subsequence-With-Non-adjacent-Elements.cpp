
class Solution {
public:
    int rec(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int pick = nums[i] + rec(i + 2, nums, dp);
        int notPick = rec(i + 1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int tab(vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        for (int j = n - 1; j >= 0; j--) {
            int pick = nums[j] + dp[j + 2];
            int notPick = dp[j + 1];

            dp[j] = max(pick, notPick);
        }

        return dp[0];
    }

    int maximumSumSubsequence(vector<int>& nums,
                              vector<vector<int>>& queries) {
        int n = nums.size();
        const int MOD = 1e9 + 7;
        long long sum = 0;

        for (auto& it : queries) {
            nums[it[0]] = it[1];

            vector<int> dp(n + 2, 0);
            sum = (sum + tab(nums, dp)) % MOD;
        }

        return sum;
    }
};
