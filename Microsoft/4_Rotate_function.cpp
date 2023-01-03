class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN, sum = 0, n = nums.size();
        vector<int>dp(n,0);
        for(int i = 0;i < n;i++)
        {
            sum += nums[i];
            dp[0] += nums[i]*i;
        }
        for(int i = 1;i < n;i++)
        {
            dp[i] = dp[i-1] - sum + n*nums[i-1];
            ans = max(ans,dp[i-1]);
        }
        return max(ans,dp[n-1]);
    }
};
