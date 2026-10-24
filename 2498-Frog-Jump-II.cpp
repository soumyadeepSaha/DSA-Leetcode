class Solution {
public:
     bool cancross(vector<int>& stones, int mid) {
    int n = stones.size();

    for (int i = 2; i < n; i++) {
        if (stones[i] - stones[i - 2] > mid)
            return false;
    }

    return true;
}
    int maxJump(vector<int>& stones) {

        // the max alternate distance can be one of my answer
        // min alternate distance can be my another answerr
        int n = stones.size();
        int low = stones[1] - stones[0];
        int high = stones[n - 1] - stones[0];

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (cancross(stones, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};