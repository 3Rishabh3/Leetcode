class Solution {
public:
    static bool comparator(string a, string b){
        return a + b > b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        string result;
        
        for(int n : nums)
            strNums.push_back(to_string(n));
        
        sort(strNums.begin(), strNums.end(), comparator);
        
        for(string s : strNums)
            result += s;
        
                
        if(result.back() == '0' and result.front() == '0')
            return "0";
        
        return result;
    }
};