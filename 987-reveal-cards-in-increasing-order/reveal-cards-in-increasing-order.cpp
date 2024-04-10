class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       int n=deck.size();
       vector<int> result(n);
       deque<int> temp;

       sort(deck.begin(),deck.end());
       for(int i=0;i<n;i++)
       {
         temp.push_back(i);
         result[i]=0;
       }
       for(int c: deck)
       {
            int index=temp.front();
            temp.pop_front();
            result[index]=c;
            if(!temp.empty())
            {
                temp.push_back(temp.front());
                temp.pop_front();
            }
       }

        return result;
    }
};