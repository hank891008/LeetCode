class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>Set;
        int ans = 1;
        for(int i = 0; i < s.size(); i++){
            if(!Set.count(s[i])){
                Set.insert(s[i]);
            }
            else{
                Set.clear();
                Set.insert(s[i]);
                ans++;
            }
        }
        return ans;
    }
};