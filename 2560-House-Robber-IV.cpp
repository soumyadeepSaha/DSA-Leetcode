class Solution {
public:
    int rec(int i, int countS, vector<int>& nums, int k,
            vector<vector<int>>& dp) {

        if (countS == k)
            return 0;

        if (i >= nums.size() ||
            nums.size() - i < 2 * (k - countS) - 1)
            return INT_MAX;

        if (dp[i][countS] != -1)
            return dp[i][countS];

        // Pick current house
        int pick = rec(i + 2, countS + 1, nums, k, dp);
        if (pick != INT_MAX)
            pick = max(pick, nums[i]);

        // Skip current house
        int notpick = rec(i + 1, countS, nums, k, dp);

        return dp[i][countS] = min(pick, notpick);
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(n + 2, vector<int>(k + 1, -1));

        return rec(0, 0, nums, k, dp);
    }
};