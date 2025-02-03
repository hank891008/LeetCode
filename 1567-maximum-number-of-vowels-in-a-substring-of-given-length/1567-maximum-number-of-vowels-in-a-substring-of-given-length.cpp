class Solution {
public:
    int maxVowels(string s, int k) {
        string vowel = "aeiou";
        int now = 0;
        for(int i = 0; i < k; i++){
            now += (vowel.find(s[i]) != -1);
        }
        int maxx = now;
        for(int i = k; i < s.size(); i++){
            now = now - (vowel.find(s[i - k]) != -1) + (vowel.find(s[i]) != -1);
            maxx = max(maxx, now);
            if(maxx == k){
                break;
            }
        }
        return maxx;
    }
};