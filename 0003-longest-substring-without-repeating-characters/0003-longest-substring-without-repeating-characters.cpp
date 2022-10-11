class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxx = 0;
        map<char, int>mp;
        for(int i = 0; i < s.size(); i++){
            if(!mp.count(s[i])){
                mp[s[i]] = i;
            }
            else{
                auto it = mp.begin();
                while(it != mp.end()){
                    if(it->second < mp[s[i]]){
                        mp.erase(it++);
                    }
                    else{
                        it++;
                    }
                }
                mp[s[i]] = i;
            }
            // vector<pair<int, char>>p;
            // for(auto it: mp){
            //     p.push_back({it.second, it.first});
            // }
            // cout << mp.size() << '\n';
            // sort(p.begin(), p.end());
            // for(int i = 0; i < p.size(); i++){
            //     cout << p[i].second;
            // }
            // cout << '\n';
            maxx = max(maxx, (int)mp.size());
        }
        return maxx;
    }
};