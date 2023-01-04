class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n);
        vector<int>ans;
        for(int i = 0;i < n;i++)
        {
            if(i == 0)
                dp[i].push_back(nums[i]);
            else
            {
                vector<int> temp;
                for(int j = 0;j < i;j++)
                {
                    if(nums[i]%nums[j] != 0)
                        continue;
                    if(temp.size() < dp[j].size())
                        temp = dp[j];
                }
                dp[i] = temp;
                dp[i].push_back(nums[i]);
            }
            if(ans.size() < dp[i].size())
                ans = dp[i];
        }
        return ans;
    }
};
