class Solution {
public:
    static int dis(vector<int>& a, vector<int>& b)
    {
        return ((a[1]-b[1])*(a[1]-b[1])+(a[0]-b[0])*(a[0]-b[0]));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        unordered_map<int,int>m;
        for(int i = 0;i < n;i++)
        {
            map<int,int>m;
            for(int j = 0;j < n;j++)
            {
                if(i != j)
                    m[dis(points[i],points[j])]++;
            }
            for(auto it : m)
            {
                if(it.second > 1)
                    ans += it.second * (it.second-1);
            }
        }
        return ans;
    }
};
