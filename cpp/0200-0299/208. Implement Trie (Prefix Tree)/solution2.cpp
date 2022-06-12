// Optimized for performance
class TrieNode {
public:
    char c;
    vector<TrieNode*> nodes;
    bool endOfWord = false;
    
public:
    TrieNode(char c=0) : c(c), nodes(26) {
        
    }
    
    TrieNode* traverse(const string& prefix) {
        TrieNode* curr = this;
        for (auto c : prefix) {
            c -= 'a';
            if (!curr->nodes[c])
                return nullptr;
            curr = curr->nodes[c];
        }
        return curr;
    }
};


class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* curr = root;
        for (auto c : word) {
            c -= 'a';
            
            // Create the TrieNode if not exists
            if (!curr->nodes[c])
                curr->nodes[c] = new TrieNode(c);
            curr = curr->nodes[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(const string& word) {
        TrieNode* node = root->traverse(word);
        return (node && node->endOfWord);
    }
    
    bool startsWith(const string& prefix) {
        TrieNode* node = root->traverse(prefix);
        return node ? true : false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */