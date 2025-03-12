class Solution {
public:
    struct node{
        bool isWord = false;
        map<char, node*> next;
    };
    void dfs(string word, node* now, vector<string>& v){
        if(v.size() == 3){
            return;
        }
        if(now->isWord){
            v.emplace_back(word);
        }
        for(auto [alpha, next_node]: now->next){
            dfs(word + alpha, next_node, v);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        node* root = new node();
        for(auto product: products){
            node* now = root;
            for(auto ch: product){
                if(!now->next.count(ch)){
                    now->next[ch] = new node();
                }
                now = now->next[ch];
            }
            now->isWord = true;
        }
        vector<vector<string>> ans(searchWord.size());
        
        node* now = root;
        string word;
        for(int i = 0; i < searchWord.size(); i++){
            if(!now->next.count(searchWord[i])){
                break;
            }
            now = now->next[searchWord[i]];
            word += searchWord[i];
            dfs(word, now, ans[i]);
        }
        return ans;
    }
};