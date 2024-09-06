/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
  
class Solution {
  
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head;
        ListNode* prev = dummy;
        
        unordered_set<int> numset(nums.begin(),nums.end());
        while(current != nullptr)
        {
            if(numset.count(current->val))
            {
                prev->next = current->next;
            }
            else
            {
                    prev = current;
            }
            current = current->next;
        }
        return dummy->next;
    }
};