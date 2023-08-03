class Solution {
public:
    vector<vector<char>> v;
    vector<string> ans;
    void dfs(int idx, string str){
        if(idx == v.size()){
            ans.emplace_back(str);
            return;
        }
        for(int i = 0; i < v[idx].size(); i++){
            dfs(idx + 1, str + v[idx][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return ans;
        }
        for(int i = 0; i < digits.size(); i++){
            int now = digits[i] - '2';
            vector<char>tmp;
            if(now == 5){
                tmp.emplace_back('p');
                tmp.emplace_back('q');
                tmp.emplace_back('r');
                tmp.emplace_back('s');
            }
            else if(now == 6){
                tmp.emplace_back('t');
                tmp.emplace_back('u');
                tmp.emplace_back('v');
            }
            else if(now == 7){
                tmp.emplace_back('w');
                tmp.emplace_back('x');
                tmp.emplace_back('y');
                tmp.emplace_back('z');
            }
            else{
                tmp.emplace_back(now * 3 + 'a');
                tmp.emplace_back(now * 3 + 'b');
                tmp.emplace_back(now * 3 + 'c');
            }
            v.emplace_back(tmp);
        }
        dfs(0, "");
        return ans;
    }
};