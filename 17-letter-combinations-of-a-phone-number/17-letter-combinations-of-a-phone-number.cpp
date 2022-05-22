class Solution {
public:
    void solve(string& digits, int i, const vector<string>& chars, string temp, vector<string>& ans){
        if(i == digits.length()){
            ans.push_back(temp);
            return;
        }
        
        int d = digits[i] - '0';
        for(char ch : chars[d])
            solve(digits, i+1, chars, temp + ch, ans);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        const vector<string> chars = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        string temp = "";
        
        solve(digits, 0, chars, temp, ans);
        return ans;
    }
};