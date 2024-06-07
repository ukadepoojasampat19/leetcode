class Trie {
public:
    //structre define kele
    struct trieNode
    {
        bool isendofnode;
        trieNode *children[26];
    };

    //form new node
    trieNode* getnode()
    {
        trieNode *newNode = new trieNode();
        newNode->isendofnode = false;
        for(int i=0;i<26;i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    trieNode* root;
    Trie() {
        root = getnode();
    }
    
    void insert(string word) {
    trieNode* crawler = root;
    for(int i=0;i< word.length();i++)
    {
        
        char ch = word[i];
        int idx =  ch - 'a';

        if(crawler->children[idx] == NULL)
        {
            crawler->children[idx] = getnode();
        }

        crawler = crawler->children[idx];
    }

        crawler->isendofnode = true;
        
    }
    
    bool search(string word) {
     trieNode* crawler = root;
    for(int i=0;i< word.length();i++)
    {
       
        char ch = word[i];
        int idx =  ch - 'a';

        if(crawler->children[idx] == NULL)
        {
            return false;;
        }

        crawler = crawler->children[idx];
    }

    if(crawler->isendofnode == true && crawler != NULL)
    {
        return true;
    }
    return false;
        
    }
    
    bool startsWith(string prefix) {
     trieNode* crawler = root;
        int i;
     for(i=0;i< prefix.length();i++)
    {
       
        char ch = prefix[i];
        int idx =  ch - 'a';

        if(crawler->children[idx] == NULL)
        {
            return false;;
        }

        crawler = crawler->children[idx];
    }

    if( i == prefix.length())
    {
        return true;
    }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */