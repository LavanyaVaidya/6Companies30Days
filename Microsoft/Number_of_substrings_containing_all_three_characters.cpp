class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), ans = 0, j = 0;
        map<char,int>m;
        m['a'] = 0;
        m['b'] = 0;
        m['c'] = 0;
        for(int i = 0;i < n;i++)
        {
            m[s[i]]++;
            while(m['a'] && m['b'] && m['c'])
            {
                ans += n - i;
                m[s[j++]]--;
            }
        }
        return ans;
    }
};
