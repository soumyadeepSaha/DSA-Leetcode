class Solution {
public:
    // int rec(int n, vector<int>& dp) {
    //      if (n < 0)
    //         return 0;
    //     if (n == 0 || n== 1 )
    //         return 1;
    //      if(n==2)return 2;   
       
    //     if (dp[n] != -1)
    //         return dp[n];

    //     return dp[n] = rec(n - 2,dp) + rec(n - 1,dp);
    // }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
    int prev2=1;
    int prev1=1;
     int curr1=0;
         for(int i=2; i<=n;i++){
        curr1 = prev2 + prev1;
        prev2=prev1;
        prev1=curr1;
         }

        return prev1;
    }
};