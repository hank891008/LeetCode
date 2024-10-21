class Solution {
public:
    int maxx = 0;
    unordered_set<string> used;
    void dfs(string s, int start){
        if(start == s.size()){
            maxx = max(maxx, (int)used.size());
            return;
        }
        for(int end = start + 1; end <= s.size(); end++){
            string st = s.substr(start, end - start);
            if(!used.count(st)){
                used.insert(st);
                dfs(s, end);
                used.erase(st);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        dfs(s, 0);
        return maxx;
    }
};