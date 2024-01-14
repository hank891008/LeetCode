class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        int n = word1.size();
        vector<int>v1(26), v2(26);
        set<int>s1, s2;
        for(int i = 0; i < n; i++){
            v1[word1[i] - 'a']++;
            v2[word2[i] - 'a']++;
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (v1 == v2) && (s1 == s2);
        
    }
};