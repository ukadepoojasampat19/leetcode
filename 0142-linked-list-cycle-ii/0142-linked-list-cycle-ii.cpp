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
    ListNode *detectCycle(ListNode *head) {
      //  map<ListNode*, int> mp;
        ListNode* s=head;
        ListNode* f=head;
        while(f != nullptr && f->next != nullptr)
        {
            s=s->next;
            f=f->next->next;
            if(f == s)
            {
                f=head;
                while(f != s) 
                {
                    f=f->next;
                    s=s->next;
                  
                }
                  return f;
            }
        }
       
        return nullptr;
        
    }
};