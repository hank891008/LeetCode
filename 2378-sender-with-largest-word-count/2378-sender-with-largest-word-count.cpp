class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = senders.size();
        unordered_map<string, int> mp;
        string ans;
        int max_cnt = 0;
        for(int i = 0; i < n; i++){
            mp[senders[i]] += (count(messages[i].begin(), messages[i].end(), ' ') + 1);
            if(mp[senders[i]] > max_cnt || (mp[senders[i]] == max_cnt && senders[i] > ans)){
                max_cnt = mp[senders[i]];
                ans = senders[i];
            }
        }
        return ans;
    }
};