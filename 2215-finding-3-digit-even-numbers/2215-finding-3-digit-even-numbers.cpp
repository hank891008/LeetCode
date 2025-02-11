class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for(auto d: digits){
            cnt[d]++;
        }
        vector<int> ans;
        for(int i = 100; i < 999; i += 2){
            int a = i % 10, b = (i / 10) % 10, c = i / 100;
            cnt[a]--;
            cnt[b]--;
            cnt[c]--;
            if(cnt[a] >= 0 && cnt[b] >= 0 && cnt[c] >= 0){
                ans.emplace_back(i);
            }
            cnt[a]++;
            cnt[b]++;
            cnt[c]++;
        }
        return ans;
    }
};