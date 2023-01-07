class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int num = 0;
        map<pair<int,int>,int>m;
        //increment for bottom-left and top-right point
        //decrement for bottom-right and top-left point
        for(auto it : rectangles)
        {
            m[{it[0],it[1]}]++;
            m[{it[2],it[3]}]++;
            m[{it[2],it[1]}]--;
            m[{it[0],it[3]}]--;
        }
        //idea is that, if all these rectangles are forming a bigger rectangle
        //only outermost vertices will remain
        //all other vertices would cancel out each other
        for(auto it : m)
        {
            if(abs(it.second) == 1)
                num++;
            if(abs(it.second) > 1)
                return 0;
        }
        return num == 4;
    }
};
