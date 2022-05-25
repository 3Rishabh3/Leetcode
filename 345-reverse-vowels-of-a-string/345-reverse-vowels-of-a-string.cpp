class Solution {
public:
    string reverseVowels(string s) {
        string ans = "";
        vector<char> temp;
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(ch == 'a' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U' or ch == 'e' or ch == 'i' or ch == 'o' or  ch == 'u'){
                temp.push_back(ch);
                ans += '#';
            }
                
            else{
                ans += ch;
            }
        }
        
        int j = 0;
        for(int i = temp.size()-1; i >= 0; i--){
            while(ans[j] != '#' && j < ans.size()){
                ++j;
            }
            if(j < ans.size())
            ans[j] = temp[i];
        }
        
        return ans;
    }
};