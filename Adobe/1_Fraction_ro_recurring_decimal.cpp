class Solution {
public:
    string fractionToDecimal(int n, int denominator) {
        long long numerator = n;
        if(numerator == 0) return "0";
        string ans = "", fraction = "";
        if(numerator < 0 ^ denominator < 0) ans += "-";
        numerator = abs(numerator);
        denominator = abs(denominator);
        ans += to_string(numerator/denominator);
        if(numerator%denominator == 0) return ans;
        unordered_map<int,int>m;
        while(1)
        {
            if(numerator % denominator == 0)
            {
                ans += "." + fraction;
                break;
            }
            numerator = (numerator%denominator)*10;
            if(m.find(numerator) == m.end())
            {
                fraction += to_string(numerator/denominator);
                m[numerator] = fraction.size()-1;
            }
            else
            {
                fraction.insert(m[numerator],1,'(');
                fraction += ")";
                ans += "." + fraction;
                break;
            }
            
        }
        return ans;
    }
};
