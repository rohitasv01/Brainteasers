class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for(char ch : s)
        {
            if(ch == '(')
            {
                // 📥 Add '(' only if it is not the outermost one
                if(depth > 0)
                    ans.push_back(ch);

                depth++;
            }
            else
            {
                depth--;

                // 📤 Add ')' only if it is not the outermost one
                if(depth > 0)
                    ans.push_back(ch);
            }
        }

        return ans;
    }
};