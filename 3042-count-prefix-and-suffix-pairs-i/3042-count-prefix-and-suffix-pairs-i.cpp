class Solution {
public:
    bool check(string a, string b){
        bool r = (b.find(a) == 0);
        if(!r){
            return false;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        return b.find(a) == 0;
    
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                ans += check(words[i], words[j]);
            }
        }
        return ans;
    }
};