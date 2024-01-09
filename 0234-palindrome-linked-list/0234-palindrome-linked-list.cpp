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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int> arr;
        int i=0;
        while(temp != nullptr)
        {
            arr.push_back(temp->val);
            i++;
            temp=temp->next;
        }
     temp=head;
       
        for(auto it=arr.rbegin(); it != arr.rend() && temp != nullptr; ++it)
        {
            if(*it == temp->val)
            {
                temp=temp->next;
            }
            else
            {
                return false;
            }
           
        }
        return true;
        
        
        
    }
};