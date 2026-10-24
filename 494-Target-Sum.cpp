class Solution {
public:
    int rec(int i, vector<int>& nums, int t, int sum) {
     
        if(i==nums.size()){
            return (sum==t)?1:0;
        }
       
        double l = rec(i + 1, nums, t, sum + nums[i]);
        double r = rec(i + 1, nums, t, sum - nums[i]);

        return l + r;
    }

    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();

        int left = 0;

        return rec(0, nums, t, left);
    }
};