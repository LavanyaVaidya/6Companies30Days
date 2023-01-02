class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& path, int k, int n, int sum, int num, int number)
    {
        if(num == k)
        {
            if(sum == n)
                ans.push_back(path);
            return;
        }
        for(int i = number+1;i <= 9;i++)
        {
            path.push_back(i);
            fun(ans,path,k,n,sum+i,num+1,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>path;
        fun(ans,path,k,n,0,0,0);
        return ans;
    }
};
