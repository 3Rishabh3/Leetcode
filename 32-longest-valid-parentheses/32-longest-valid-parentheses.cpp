class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> ch;
        stack<int> idx;
        int ans = 0;
        char c;
        idx.push(-1);
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                ch.push(s[i]);
                idx.push(i);
            }
            else{
                if(!ch.empty()){
                    ch.pop();
                    idx.pop();
                    ans = max(ans, i-idx.top());
                }
                else{
                    idx.push(i);
                }
            }
        }
        return ans;
    }
};