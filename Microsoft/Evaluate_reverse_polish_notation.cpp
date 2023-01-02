class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string>stk;
        for(int i = 0;i < n;i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" && i < n)
            {
                long long num = stoll(stk.top());
                stk.pop();
                if(tokens[i] == "+")
                num += stoll(stk.top());
                if(tokens[i] == "-")
                num = stoll(stk.top())-num;
                if(tokens[i] == "*")
                num *= stoll(stk.top());
                if(tokens[i] == "/")
                num = stoll(stk.top())/num;
                stk.pop();
                stk.push(to_string(num));
            }
            else
            {
                stk.push(tokens[i]);
            }
        }
        return (stoi(stk.top()));
    }
};
