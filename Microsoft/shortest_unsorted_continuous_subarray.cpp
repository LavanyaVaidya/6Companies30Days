class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), mini = nums[n-1], maxi = nums[0], a = 0, b = 0;
        //detect the first element which has a smaller element on it's RHS
        for(int i = 0;i < n;i++)
        {
            if(nums[i] < maxi)
                a = i+1;
            maxi = max(maxi,nums[i]);
        }
        //detect the first element which has a bigger element on it's LHS
        for(int i = n-1;i >= 0;i--)
        {
            if(nums[i] > mini)
                b = i;
            mini = min(mini,nums[i]);
        }
        return a-b;
    }
};
