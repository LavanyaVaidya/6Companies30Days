class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cows = 0;
        unordered_map<char,int>m1,m2;
        for(int i = 0;i < secret.size();i++)
        {
            if(secret[i] == guess[i])
                bull++;
            m1[secret[i]]++;
            m2[guess[i]]++;
        }
        for(auto it : m1)
        {
            if(m2.find(it.first) != m2.end())
                cows += min(it.second,m2[it.first]);
        }
        return to_string(bull)+"A"+to_string(cows-bull)+"B";
    }
};
