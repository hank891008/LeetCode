class WordDictionary {
public:
    struct Trie{
        bool end;
        Trie* next[26];
    };
    Trie* head;
    WordDictionary() {
        head = new Trie();
    }
    
    void addWord(string word) {
        Trie* now = head;
        for(auto w: word){
            int idx = w - 'a';
            if(now->next[idx] == NULL){
                now->next[idx] = new Trie();
            }
            now = now->next[idx];
        }
        now->end = true;
    }
    
    bool search(string word) {
        queue<Trie*> q;
        q.emplace(head);
        for(int i = 0; i < word.size(); i++){
            int sz = q.size();
            while(sz--){
                Trie* now = q.front();  q.pop();
                if(word[i] == '.'){
                    for(int j = 0; j < 26; j++){
                        if(now->next[j] != NULL){
                            q.emplace(now->next[j]);
                        }
                    }
                }
                else if(now->next[word[i] - 'a'] != NULL){
                    q.emplace(now->next[word[i] - 'a']);
                }
            }
        }
        while(!q.empty()){
            Trie* now = q.front();  q.pop();
            if(now->end == true){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */