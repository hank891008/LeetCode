class Solution {
public:
    struct Item{
        string w;
        int k;
        Item();
        Item(string w, int k):w(w), k(k){}
        bool operator<(const Item& rhs)const{
            return k < rhs.k || (k == rhs.k && w > rhs.w);
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>v;
        map<string, int>mp;
        priority_queue<Item>pq;
        
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto it: mp){
            pq.push(Item(it.first, it.second));
        }
        while(k != 0){
            //cout << pq.top().w <<' ' << pq.top().k<< '\n';
            v.push_back(pq.top().w);
            pq.pop();
            k--;
        }
        return v;
    }
};