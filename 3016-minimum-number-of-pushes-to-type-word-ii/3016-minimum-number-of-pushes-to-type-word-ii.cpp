class Solution {
public:
    int minimumPushes(string word) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(auto w: word){
            freq[w - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0){
                break;
            }
            if(i % 8 == 0){
                cnt++;
            }
            ans += freq[i] * cnt;
        }
        return ans;
    }
};