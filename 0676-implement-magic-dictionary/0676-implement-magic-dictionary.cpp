class MagicDictionary {
public:
    struct Trie{
        bool end;
        Trie* next[26];
    };
    Trie* root = new Trie();
    MagicDictionary() {
        
    }
    bool _search(string word){
        Trie* now = root;
        for(auto w: word){
            int idx = w - 'a';
            if(now->next[idx] == NULL){
                return false;
            }
            now = now->next[idx];
        }
        return now->end;
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word: dictionary){
            Trie* now = root;
            for(auto w: word){
                int idx = w - 'a';
                if(now->next[idx] == NULL){
                    now->next[idx] = new Trie();
                }
                now = now->next[idx];
            }
            now->end = true;
        }
    }
    
    bool search(string searchWord) {
        for(int i = 0; i < searchWord.size(); i++){
            char origin = searchWord[i];
            for(int j = 'a'; j <= 'z'; j++){
                if(origin == j){
                    continue;
                }
                searchWord[i] = j;
                if(_search(searchWord)){
                    return true;
                }
                
            }
            searchWord[i] = origin;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */