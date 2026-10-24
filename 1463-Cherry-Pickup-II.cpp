class Solution {
public:
    int rec(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m,vector<vector<vector<int>>>&dp) {

        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m || i == n)
            return 0;

        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int tot = 0;
        if (j1 == j2) {
            tot = grid[i][j1];
        } else {
            tot = grid[i][j1] + grid[i][j2];
        }
        int maxi = 0;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                maxi = max(maxi, rec(i + 1, j1 + d1, j2 + d2, grid, n, m,dp));
            }
        }

        return dp[i][j1][j2]=tot + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));

        return rec(0, 0,  m - 1, grid, n, m,dp);
    }
};