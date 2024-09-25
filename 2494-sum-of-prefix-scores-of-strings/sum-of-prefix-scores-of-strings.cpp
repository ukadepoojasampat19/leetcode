struct Node
{
    Node* link[26];
    int ct =0;


    bool containKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node)
    {
        link[ch -'a'] = node;
    }
    Node* get(char ch)
    {
        return link[ch -'a'];
    }
    void increment()
    {
        ct += 1;
    }
    int getCount()
    {
        return ct;
    }
};



class Solution {
private:
        Node* root;
public:

    Solution()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increment();
        }

    }

    bool startWith(string prefix,vector<int>& res, int n)
    {
        Node* node = root;
        int count =0;
        for(int i=0;i<prefix.size();i++)
        {
            
            node = node->get(prefix[i]);
            count += node->getCount();

        }
        res[n] = count;
        return true;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Solution obj;
        vector<int> res(words.size());
        for(int i=0;i<words.size();i++)
        {
            obj.insert(words[i]);
        }
        for(int i=0;i<words.size();i++)
        {
            obj.startWith(words[i],res,i);
        }

        return res;
    }
};