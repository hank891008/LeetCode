struct node{
    bool end;
    node* next[26];
    
    node(){
        this->end = false;
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* tmp = root;
        for(int i = 0; i < word.size(); i++){
            int w = word[i] - 'a';
            if(tmp->next[w] == NULL){
                tmp->next[w] = new node();
            }
            tmp = tmp->next[w];
        }
        tmp->end = true;
    }
    
    bool search(string word) {
        node* tmp = root;
        for(int i = 0; i < word.size(); i++){
            int w = word[i] - 'a';
            if(tmp->next[w] == NULL){
                return false;
            }
            else{
                tmp = tmp->next[w];
            }
        }
        return tmp->end;
    }
    
    bool startsWith(string prefix) {
        node* tmp = root;
        for(int i = 0; i < prefix.size(); i++){
            int w = prefix[i] - 'a';
            if(tmp->next[w] == NULL){
                return false;
            }
            else{
                tmp = tmp->next[w];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */