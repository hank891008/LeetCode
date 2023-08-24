class Solution {
public:
    int used[1005][30][30];
    int dfs(int idx, int s, int e, vector<string>& words){
        if(idx == words.size()){
            return 0;
        }
        if(used[idx][s][e] != 0){
            return used[idx][s][e];
        }
        int first = words[idx].front() - 'a';
        int last = words[idx].back() - 'a';
        int minn = INT_MAX;
        minn = min(minn, (int)words[idx].size() - (e == first) + dfs(idx + 1, s, last, words));
        minn = min(minn, (int)words[idx].size() - (s == last) + dfs(idx + 1, first, e, words));
        return used[idx][s][e] = minn;
        
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        return words[0].size() + dfs(1, words[0].front() - 'a', words[0].back() - 'a', words);
    }
};