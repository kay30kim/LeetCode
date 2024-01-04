class WordDictionary {
private:
    typedef struct Node {
        bool end = false;
        Node* child[26];
    }Node;
    Node *root;
public:
    WordDictionary() {
        // if (root) delete(root);
        root = new Node();
    }
    
    void addWord(string word) {
        Node *ptr = root;
        for (auto cha : word) {
            if (ptr->child[cha - 'a'] == NULL)
                ptr->child[cha - 'a'] = new Node();
            ptr = ptr->child[cha - 'a'];
        }
        ptr->end = true;
    }
    
    void searchWPtr(string word, Node *ptr, bool &ans) {
        if (word.size() == 0 && ptr->end)
            ans = true;
        if (word.size() == 0)
            return;
        if (word[0] == '.') {
            // check every child
            for (int  j = 0; j < 26; j++) {
                if (ptr->child[j]){ // ★ copy with '\0'
                    searchWPtr(word.substr(1, word.size()), ptr->child[j], ans);
                }
            }
            // skip '.'
            // searchWPtr(word.substr(1, word.size()), ptr, ans);
        } else if (ptr->child[word[0] -'a'] == NULL) {
            return;
        } else {
            searchWPtr(word.substr(1, word.size()), ptr->child[word[0] - 'a'], ans);
        }
    }
    
    bool search(string word) {
        bool ans = false;
        searchWPtr(word, root, ans);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */