/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      /* map<ListNode*,int> mp;
        ListNode* temp=head;
        while(temp != nullptr)
        {
            if(mp.find(temp) != mp.end())
            {
                return true;
            }
            else
            {
                mp[temp]=1;
                temp=temp->next;
            }
        }
        return false;
        */
        
        unordered_set<ListNode*> visited;
        ListNode* temp=head;
        while(temp!= nullptr)
        {
            if(visited.find(temp) != visited.end())
            {
                return true;
            }
            visited.insert(temp);
            temp=temp->next;
        }
        
        return false;
    }
};