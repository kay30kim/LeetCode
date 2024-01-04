class Trie {
private:
    typedef struct Node {
        bool end = false;
        Node *child[26];
    }Node;
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *ptr = root;
        for (auto cha : word) {
            if (ptr->child[cha - 'a'] == NULL)
                ptr->child[cha - 'a'] = new Node();
            ptr = ptr->child[cha - 'a'];
        }
        ptr->end = true;
    }
    
    bool search(string word) {
        Node *ptr = root;
        for (auto cha : word) {
            if (ptr->child[cha - 'a'] == NULL)
                return false;
            ptr = ptr->child[cha - 'a'];
        }
        return ptr->end;
    }
    
    bool startsWith(string prefix) {
        Node *ptr = root;
        for (auto cha : prefix) {
            if (ptr->child[cha - 'a'] == NULL)
                return false;
            ptr = ptr->child[cha -'a'];
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