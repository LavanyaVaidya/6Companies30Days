class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>freq, need;
        for(int n : nums)
            freq[n]++;
        for(int n : nums)
        {
            if(freq[n] == 0) continue;
            if(need[n] > 0)
            {
                need[n]--;
                freq[n]--;
                need[n+1]++;
            }
            else if(freq[n+1] > 0 && freq[n+2] > 0)
            {
                freq[n]--;
                freq[n+1]--;
                freq[n+2]--;
                need[n+3]++;
            }
            else
                return 0;
        }
        return 1;
    }
};
