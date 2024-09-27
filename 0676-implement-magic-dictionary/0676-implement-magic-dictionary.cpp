class MagicDictionary {
public:
    vector<string> dict;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        dict = dictionary;
    }
    
    bool search(string searchWord) {
        for(auto d: dict){
            if(d.size() == searchWord.size()){
                int cnt = 0;
                for(int i = 0; i < d.size(); i++){
                    cnt += (d[i] != searchWord[i]);
                    if(cnt >= 2){
                        break;
                    }
                }
                if(cnt == 1){
                    return true;
                }
            }
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