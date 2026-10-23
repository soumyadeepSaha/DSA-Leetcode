class Solution {
public:
    // int rec(int i, vector<int>& stones, int n, unordered_map<int, int>& mpp,
    //         double jumps, vector<vector<int>>& dp) {

    //     if (i == stones.size() - 1)
    //         return true;

    //     if (dp[i][jumps] != -1)
    //         return dp[i][jumps];

    //     bool ans = false;
    //     for (int jp = jumps - 1; jp <= jumps + 1; jp++) {

    //         if (jp <= 0)
    //             continue;

    //         // now i have different combination and i will check if he can take
    //         // the jump and then he will jump if he can

    //         double j = stones[i] + jp;

    //         if (mpp.find(j) != mpp.end()) {

    //             ans = rec(mpp[j], stones, n, mpp, jp, dp);
    //         }

    //         if (ans)
    //             return dp[i][jumps] = ans;
    //     }

    //     return dp[i][jumps] = false;
    // }

    bool canCross(vector<int>& stones) {

        int n = stones.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < stones.size(); i++)
            mpp[stones[i]] = i;

        if (stones[1] != 1)
            return false;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

       for (int jumps = 0; jumps <= n; jumps++)
            dp[n - 1][jumps] = true;

        
        for (int i = n - 2; i >= 1; i--) {

            for (int jumps = n - 1; jumps >= 1; jumps--) {
                for (int jp = jumps - 1; jp <= jumps + 1; jp++) {
                 bool ans=false;
                    if (jp <= 0 || jp>n)
                        continue;

                    // now i have different combination and i will check if he
                    // can take the jump and then he will jump if he can

                    int j = stones[i] + jp;

                    if (mpp.find(j) != mpp.end()) {

                        ans = dp[mpp[j]][jp];
                    }

                    if (ans)
                        dp[i][jumps] = ans;
                }
    
            }
        }

        return dp[1][1];
    }
};