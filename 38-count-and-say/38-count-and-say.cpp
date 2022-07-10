class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string s = countAndSay(n-1);
        string res = "";
        int count = 0;
        
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            ++count;
            if(ch != s[i+1]){
                res += to_string(count);
                res += ch;
                count = 0;
            }
        }
            
        return res;
    }
};