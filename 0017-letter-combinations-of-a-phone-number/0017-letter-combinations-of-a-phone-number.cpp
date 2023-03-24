class Solution {
public:
    void solve(int index, string s, unordered_map<char,string> &m, vector<string>&ans,string &check){
        if(index==s.size()){
            ans.push_back(check);
            return;
        }
        for(int i=0;i<m[s[index]].size();i++){
            check.push_back(m[s[index]][i]);
            solve(index+1,s,m,ans,check);
            check.pop_back();
        }
            
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string check;
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        
        if(digits.size()==0)
                return ans;
        solve(0,digits,m,ans,check);
        
        return ans;
    }
};