class Solution {
public:
    int deleteAndEarnRecursive(vector<int> &nums, unordered_map<int, int> freqMap, int cntIndex) {
        if (cntIndex >= nums.size())
            return 0;
        int inclusive =
                (nums.at(cntIndex) * freqMap[nums.at(cntIndex)]) + deleteAndEarnRecursive(nums, freqMap, cntIndex + 2);
        int exclusive = deleteAndEarnRecursive(nums, freqMap, cntIndex + 1);
        return max(inclusive, exclusive);
    }

    int deleteAndEarnMemoization(vector<int> &nums, unordered_map<int, int> freqMap, int cntIndex, int *dp) {
        if (cntIndex >= nums.size())
            return 0;
        if (dp[cntIndex] != -1)
            return dp[cntIndex];
        int inclusive =
                (nums.at(cntIndex) * freqMap[nums.at(cntIndex)]) +
                deleteAndEarnMemoization(nums, freqMap, cntIndex + 2, dp);
        int exclusive = deleteAndEarnMemoization(nums, freqMap, cntIndex + 1, dp);
        dp[cntIndex] = max(inclusive, exclusive);
        return max(inclusive, exclusive);
    }

    static int deleteAndEarnDynamicProgramming(vector<int> &nums, unordered_map<int, int> freqMap) {
        int dp[nums.size()];
        dp[0] = nums.at(0) * freqMap[nums.at(0)];
        dp[1] = nums.at(1) * freqMap[nums.at(1)];

        for (int i = 2; i < nums.size(); i++) {
            int inclusive = (nums.at(i) * freqMap[nums.at(i)]) + dp[i - 2];
            int exclusive = dp[i - 1];
            dp[i] = max(inclusive, exclusive);
        }
        return dp[nums.size() - 1];
    }

    int deleteAndEarn(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> finalNums;
        unordered_map<int, int> freqMap;

        for (int i = 0; i <= nums.at(nums.size() - 1); i++) {
            finalNums.push_back(i);
            freqMap[i] = 0;
        }
        for (int &num : nums) {
            freqMap[num] += 1;
        }
        return deleteAndEarnDynamicProgramming(finalNums, freqMap);
    }
};