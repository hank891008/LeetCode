class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        set<char>s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        for(int i = left; i <= right; i++){
            if(s.count(words[i][0]) && s.count(words[i].back())){
                ans++;
            }
        }
        return ans;
    }
};