class Solution {
public:
    struct Trie{
        Trie* next[2] = {};
    };
    void add(Trie *root, int num){
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(root->next[bit] == NULL){
                root->next[bit] = new Trie();
            }
            root = root->next[bit];
        }
    }
    int find(Trie *root, int num){
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(root->next[!bit]){
                root = root->next[!bit];
                ans |= (1 << i);
            }
            else{
                root = root->next[bit];
            }
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(auto num: nums){
            add(root, num);
        }
        int ans = 0;
        for(auto num: nums){
            ans = max(ans, find(root, num));
        }
        return ans;
    }
};