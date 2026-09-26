class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        int num = 0;

        // The operator that comes before the current number
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Build the complete number
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // If we encounter an operator OR reach the end
            if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1) {

                // Previous operator was '+'
                if (sign == '+') {
                    st.push(num);
                }

                // Previous operator was '-'
                else if (sign == '-') {
                    st.push(-num);
                }

                // Previous operator was '*'
                else if (sign == '*') {
                    int x = st.top();
                    st.pop();

                    st.push(x * num);
                }

                // Previous operator was '/'
                else if (sign == '/') {
                    int x = st.top();
                    st.pop();

                    st.push(x / num);
                }

                // Current operator becomes the sign
                // for the NEXT number
                sign = ch;

                // Reset number
                num = 0;
            }
        }

        // Add everything in the stack
        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};