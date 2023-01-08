class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(auto p1 : points)
        {
            map<double,int>count;
            for(auto p2 : points)
                if(p1 != p2)
                    ans = max(ans,++count[(double)(p1[1]-p2[1])/(p1[0]-p2[0])]);
        }
        return ans+1;
    }
};
