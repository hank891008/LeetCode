class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string new_s;
        unordered_set<int> Set(spaces.begin(), spaces.end());
        for(int i = 0; i < s.size(); i++){
            if(Set.count(i)){
                new_s += ' ';
            }
            new_s += s[i];
        }
        return new_s;
    }
};