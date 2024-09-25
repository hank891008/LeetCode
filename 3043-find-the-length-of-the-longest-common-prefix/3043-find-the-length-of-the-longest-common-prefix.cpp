class Solution {
public:
    struct Trie{
        Trie *next[10];
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie *head = new Trie();
        for(auto arr: arr1){
            string st = to_string(arr);
            Trie* now = head;
            for(int i = 0; i < st.size(); i++){
                int idx = st[i] - '0';
                if(now->next[idx] == NULL){
                    now->next[idx] = new Trie();
                }
                now = now->next[idx];
            }
        }
        int maxx = 0;
        for(auto arr: arr2){
            string st = to_string(arr);
            Trie* now = head;
            int cnt = 0;
            for(int i = 0; i < st.size(); i++){
                int idx = st[i] - '0';
                if(now->next[idx] != NULL){
                    cnt++;
                    now = now->next[idx];
                }
                else{
                    break;
                }
            }
            maxx = max(maxx, cnt);
        }
        
        return maxx;
    }
};