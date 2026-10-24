class Solution {
public:
    bool rob(int mid, vector<int>& nums, int k) {

  
        int houses = 0;
        for (int i = 0; i < nums.size(); i++) {
           
           if(nums[i]<=mid){
            houses++;

            i++;
           }
        
        }

        return houses >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (rob(mid, nums, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};